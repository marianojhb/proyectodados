"""macOS/Linux terminal regressions. Run: python3 tests/test_terminal.py"""
import os
from pathlib import Path
import pty
import re
import select
import subprocess
import tempfile
import termios
import time
import unittest


ROOT = Path(__file__).resolve().parents[1]
ANSI = re.compile(r"\x1b\[[0-9;?]*[A-Za-z]")


def read_until(fd, marker, timeout=3):
    output = b""
    deadline = time.monotonic() + timeout
    while marker not in output:
        remaining = deadline - time.monotonic()
        if remaining <= 0 or not select.select([fd], [], [], remaining)[0]:
            raise AssertionError(f"Timed out waiting for {marker!r}: {output!r}")
        output += os.read(fd, 65536)
    return output


class TerminalTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp = tempfile.TemporaryDirectory(prefix="dados-terminal-")
        cls.addClassCleanup(cls.temp.cleanup)
        directory = Path(cls.temp.name)
        source = directory / "probe.cpp"
        source.write_text('''
#include "rlutil.h"
#include "funciones.h"
#include <cstdlib>
int main(int argc, char **argv) {
    if (argc > 1) {
        mostrarDado(std::atoi(argv[1]), 1, 1);
        return 0;
    }
    std::cout << "READY" << std::endl;
    for (int i = 0; i < 3; i++) {
        int key = rlutil::getkey();
        std::cout << "KEY=" << key << std::endl;
    }
}
''', encoding="utf-8")
        cls.probe = directory / "probe"
        subprocess.run([
            os.environ.get("CXX", "c++"), "-std=c++14", "-I", str(ROOT),
            str(source), str(ROOT / "graficosDados.cpp"), "-o", str(cls.probe),
        ], check=True)

    def check_keys(self, chunks, expected):
        master, slave = pty.openpty()
        before = termios.tcgetattr(slave)
        process = subprocess.Popen([str(self.probe)], stdin=slave, stdout=slave,
                                   stderr=slave)
        try:
            read_until(master, b"READY")
            for chunk in chunks:
                os.write(master, chunk)
                if len(chunks) > 1:
                    time.sleep(0.02)  # Simulate separately arriving escape bytes.
            output = read_until(master, f"KEY={expected}".encode())
            self.assertIn(f"KEY={expected}".encode(), output)
            # Following ordinary input must not inherit leftover arrow bytes.
            os.write(master, b"xy")
            output = read_until(master, b"KEY=121")
            self.assertIn(b"KEY=120", output)
            process.wait(timeout=3)
            self.assertEqual(process.returncode, 0)
            after = termios.tcgetattr(slave)
            # macOS sets this bookkeeping flag when canonical mode is restored.
            pending = getattr(termios, "PENDIN", 0)
            after[3] &= ~pending
            before[3] &= ~pending
            self.assertEqual(after, before)
        finally:
            if process.poll() is None:
                process.kill()
                process.wait()
            os.close(master)
            os.close(slave)

    def test_keys(self):
        cases = [(b"\n", 1), (b"\r", 1), (b"\x1b", 0), (b" ", 32),
                 (b"a", 97)]
        for prefix in (b"\x1b[", b"\x1bO"):
            cases += [(prefix + suffix, key) for suffix, key in
                      [(b"A", 14), (b"B", 15), (b"C", 17), (b"D", 16)]]
        for data, expected in cases:
            with self.subTest(data=data):
                self.check_keys([data], expected)

    def test_split_arrow_sequence(self):
        self.check_keys([b"\x1b", b"[", b"B"], 15)

    def test_q_exits_from_main_menu(self):
        game = ROOT / "cmake-build-debug" / "proyectodados"
        if not game.is_file():
            self.skipTest("Build the game in cmake-build-debug first")
        master, slave = pty.openpty()
        process = subprocess.Popen([str(game)], stdin=slave, stdout=slave,
                                   stderr=slave)
        try:
            output = read_until(master, "»»".encode())
            self.assertIn(b"SALIR (q)", output)
            os.write(master, b"q")
            process.wait(timeout=3)
            self.assertEqual(process.returncode, 0)
        finally:
            if process.poll() is None:
                process.kill()
                process.wait()
            os.close(master)
            os.close(slave)

    def test_instructions_and_return_to_main_menu(self):
        game = ROOT / "cmake-build-debug" / "proyectodados"
        if not game.is_file():
            self.skipTest("Build the game in cmake-build-debug first")
        for back in (b"\n", b"\x1b"):
            with self.subTest(back=back):
                master, slave = pty.openpty()
                process = subprocess.Popen([str(game)], stdin=slave, stdout=slave,
                                           stderr=slave)
                try:
                    read_until(master, "»»".encode())
                    # Up wraps to Exit, then Credits, then Instructions.
                    for row in (14, 13, 12):
                        os.write(master, b"\x1b[A")
                        output = read_until(master, "»»".encode())
                        self.assertIn(f"\x1b[{row};22H»»".encode(), output)
                    os.write(master, b"\n")
                    output = read_until(master, "Enter o Esc: volver al menú principal.".encode())
                    text = output.decode("utf-8")
                    self.assertIn("Flechas arriba/abajo", text)
                    self.assertIn("Enter: seleccionar", text)
                    self.assertIn("q: salir inmediatamente en menús y pausas.", text)
                    self.assertIn("Objetivo: llegar a 100 puntos", text)
                    os.write(master, back)
                    output = read_until(master, "»»".encode())
                    self.assertIn(b"COMENZAR UN JUGADOR", output)
                    os.write(master, b"q")
                    process.wait(timeout=3)
                    self.assertEqual(process.returncode, 0)
                finally:
                    if process.poll() is None:
                        process.kill()
                        process.wait()
                    os.close(master)
                    os.close(slave)

    def test_q_exits_from_other_screens(self):
        game = ROOT / "cmake-build-debug" / "proyectodados"
        if not game.is_file():
            self.skipTest("Build the game in cmake-build-debug first")
        cases = [(3, b"RANKING ULTIMAS 10 PARTIDAS"),
                 (5, "Enter o Esc: volver al menú principal.".encode()),
                 (6, b"RLUTIL - TAPIO VIERROS"),
                 (0, b"RONDA N")]
        for index, marker in cases:
            with self.subTest(index=index):
                master, slave = pty.openpty()
                process = subprocess.Popen([str(game)], stdin=slave, stdout=slave,
                                           stderr=slave)
                try:
                    read_until(master, "»»".encode())
                    for _ in range(index):
                        os.write(master, b"\x1b[B")
                        read_until(master, "»»".encode())
                    os.write(master, b"\n")
                    if index == 0:
                        read_until(master, b"INGRESE SU NOMBRE:")
                        os.write(master, b"quique\n")
                    read_until(master, marker)
                    os.write(master, b"q")
                    process.wait(timeout=3)
                    self.assertEqual(process.returncode, 0)
                finally:
                    if process.poll() is None:
                        process.kill()
                        process.wait()
                    os.close(master)
                    os.close(slave)

    def test_dice_are_utf8_and_keep_their_dimensions(self):
        for face in range(1, 7):
            with self.subTest(face=face):
                output = subprocess.check_output([str(self.probe), str(face)])
                lines = ANSI.sub("", output.decode("utf-8")).splitlines()
                self.assertEqual(len(lines), 5)
                self.assertTrue(all(len(line) == 11 for line in lines))
                self.assertEqual(lines[0], "┌─────────┐")
                self.assertEqual(lines[-1], "└─────────┘")
                self.assertEqual(sum(line.count("·") for line in lines), face)


if __name__ == "__main__":
    unittest.main(verbosity=2)
