# Escalera o Cien — browser port

First playable slice: single-player, original scoring, graphical SDL2 dice,
instructions, keyboard and pointer controls. C++ runs through Emscripten/WASM;
HTML provides accessible controls. Desktop sources are unchanged.

## Build and play

Requires CMake, Emscripten (with its environment activated), and Python 3.
The initial build may download the SDL2 port.

```sh
emcmake cmake -S web -B web/build -DCMAKE_BUILD_TYPE=Release
cmake --build web/build -j
python3 -m http.server 8080 --directory web/build
```

Open <http://localhost:8080/dados.html>. Do not open the HTML directly with
`file://`: browsers must fetch the WASM over HTTP. Host the entire `web/build/`
output together (`dados.html`, JS, WASM and styles).

## Controls

- Enter a name and select **Jugar una partida**.
- Click/tap **Lanzar dados**, or use Space/Enter outside other controls.
- Three rolls complete a round; **Siguiente ronda** continues.
- **Cómo jugar** opens help; **Volver** or Esc returns without losing progress.
- `q` exits immediately outside text entry. It shows an exit screen rather
  than trying to close a browser tab. **Volver al inicio** starts over.

Six sixes reset the total but retain the current round maximum, matching the
console edition. A straight wins immediately; other victories are decided
after adding the best of three rolls at round end.

## Native rule tests

```sh
cmake -S web -B web/build-native -DDADOS_NATIVE_TESTS=ON
cmake --build web/build-native
ctest --test-dir web/build-native --output-on-failure
```

## Browser checks (optional)

After building WASM, install the optional Playwright dev dependency in `web/`
and run `npm test --prefix web`. The script uses installed Google Chrome on
macOS; elsewhere install Playwright Chromium (`npx playwright install chromium`)
or supply `CHROME_PATH`. It verifies the real WASM at desktop and 375 px widths,
including actual SDL pixels, keyboard controls and restart. Screenshots are
saved to a temporary directory printed by the runner.

## Later slices

Local multiplayer, simulated dice and ranking are not yet part of this port.
No backend, accounts or external services are required.
