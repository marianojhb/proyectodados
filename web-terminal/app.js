/* ANSI rendering and asynchronous stdin only. The game remains the original C++. */
const terminal = new Terminal({
  cols: 90, rows: 30, fontSize: 15,
  fontFamily: 'Menlo, Consolas, "Liberation Mono", monospace',
  convertEol: true, scrollback: 100, cursorBlink: true,
  theme: { background: '#ff55ff', foreground: '#ffffff', cursor: '#ffffff' }
});
terminal.open(document.getElementById('terminal'));
window.terminal = terminal;

class Input {
  constructor() { this.bytes = []; this.waiter = null; this.lineBytes = []; this.stopped = false; }
  push(text) {
    if (this.stopped) return;
    this.bytes.push(...new TextEncoder().encode(text));
    if (this.waiter) {
      const waiter = this.waiter;
      this.waiter = null;
      clearTimeout(waiter.timer);
      waiter.resolve(this.bytes.shift());
    }
  }
  pending() { return this.bytes.length; }
  async readByte(timeout) {
    if (this.stopped) return -1;
    if (this.bytes.length) return this.bytes.shift();
    return new Promise(resolve => {
      const waiter = { resolve };
      if (timeout >= 0) waiter.timer = setTimeout(() => {
        if (this.waiter === waiter) this.waiter = null;
        resolve(-1);
      }, timeout * 100);
      this.waiter = waiter;
    });
  }
  async readLineByte() {
    if (!this.lineBytes.length) {
      document.getElementById('status').textContent = 'Escribí tu respuesta y presioná Enter. Backspace borra.';
      let text = '';
      let escape = false;
      const decoder = new TextDecoder();
      while (!this.stopped) {
        const byte = await this.readByte(-1);
        if (byte < 0) return -1;
        if (escape) { if (byte >= 64 && byte <= 126 && byte !== 91) escape = false; continue; }
        if (byte === 27) { escape = true; continue; }
        if (byte === 13 || byte === 10) { terminal.write('\r\n'); break; }
        if (byte === 127 || byte === 8) {
          if (text) { text = Array.from(text).slice(0, -1).join(''); terminal.write('\b \b'); }
        } else if (byte >= 32) {
          const character = decoder.decode(Uint8Array.of(byte), { stream: true });
          text += character;
          terminal.write(character);
        }
      }
      this.lineBytes = Array.from(new TextEncoder().encode(text + '\n'));
      document.getElementById('status').textContent = 'Flechas: navegar · Enter: elegir · q: salir';
    }
    return this.lineBytes.shift();
  }
  stop() {
    this.stopped = true;
    this.bytes = [];
    if (this.waiter) {
      clearTimeout(this.waiter.timer);
      this.waiter.resolve(-1);
      this.waiter = null;
    }
  }
}

const input = new Input();
const outputDecoder = new TextDecoder();
const status = document.getElementById('status');
function stopped(code) {
  input.stop();
  status.textContent = code === 0 ? 'Programa finalizado. Podés iniciar una sesión nueva.' : 'No se pudo ejecutar el programa. Iniciá una sesión nueva para reintentar.';
  document.getElementById('restart').hidden = false;
  document.querySelectorAll('nav button').forEach(button => { button.disabled = true; });
}
var Module = {
  terminalInput: input,
  terminalOutput: bytes => terminal.write(outputDecoder.decode(bytes, { stream: true })),
  print: text => terminal.writeln(text),
  printErr: text => console.error(text),
  onRuntimeInitialized() { status.textContent = 'Flechas: navegar · Enter: elegir · q: salir'; terminal.focus(); },
  onExit: stopped,
  onAbort() { stopped(1); }
};
terminal.onData(text => input.push(text));
const keys = { up: '\x1b[A', down: '\x1b[B', left: '\x1b[D', right: '\x1b[C', enter: '\r', escape: '\x1b', q: 'q' };
document.querySelectorAll('[data-key]').forEach(button => button.addEventListener('click', () => {
  input.push(keys[button.dataset.key]);
  terminal.focus();
}));
document.getElementById('keyboard').addEventListener('click', () => terminal.focus());
document.getElementById('restart').addEventListener('click', () => location.reload());
