# Original console edition in the browser

Unlike the redesigned `web-port` branch, `web-terminal` compiles the original
C++ sources and preserves the character-based screen, dice, colors, menus,
single-player, local multiplayer, simulated input, and in-session ranking.

Emscripten/Asyncify lets the original blocking game wait for browser keyboard
input without freezing the page. xterm.js interprets the ANSI terminal output.
The only native-library changes are guarded by `__EMSCRIPTEN__` in `rlutil.h`;
the native input and sleep implementations remain unchanged.

## Build and run

Requires Emscripten, CMake, Node/npm and Python 3. From the repository root:

```sh
npm ci --prefix web-terminal
emcmake cmake -S web-terminal -B web-terminal/build -DCMAKE_BUILD_TYPE=Release
cmake --build web-terminal/build -j
python3 -m http.server 8081 --directory web-terminal/build
```

Open <http://localhost:8081/original.html>. A web server is required; `file://`
does not work for WASM. All dependencies are served locally; no runtime CDN is
required. Publish the entire build directory together, including the xterm.js
license copied there by CMake.

## Controls and behavior

- Click inside the terminal to focus the keyboard.
- Arrow keys and Enter navigate the original menu. Left/Right page instructions.
- Type names/numbers and press Enter. Backspace edits before submission.
- `q` exits from menus and pauses. Inside names it is ordinary text.
- After exit, **Iniciar de nuevo** reloads a fresh session.
- Touch buttons forward the same terminal keys. **Escribir** focuses the terminal.

The terminal deliberately keeps a **90-column, 30-row** display and original
light-magenta background. On small screens the terminal scrolls horizontally;
the game is not rearranged or replaced with responsive graphical widgets.
Ranking remains session-only, exactly as in the console edition. Restart/reload
clears it. Existing console validation and gameplay quirks are not redesigned.

## Browser regression test

```sh
npm test --prefix web-terminal
```

The test uses installed Google Chrome on macOS. On other systems, install
Playwright Chromium (`cd web-terminal` then `npx playwright install chromium`)
or set `CHROME_PATH`. Checks use the actual WASM and real keyboard events:
instructions, edited player names, simulated dice, straight victory, ranking,
two-player setup, normal rolling, q exit and session restart. Screenshots are
written to a temporary directory printed by the runner.

## Native edition

The existing root CMake project is still the native executable:

```sh
cmake --build cmake-build-debug
./cmake-build-debug/proyectodados
```
