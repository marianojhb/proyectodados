# Web port — first playable slice

Status: implemented and validated (first slice).

## Goal and approval
Make Escalera o Cien playable in a browser while preserving the console edition.
The user approved the C++/SDL2/Emscripten approach used by Proyecto-1942 and
the first slice (menu → single-player → dice → scoring), and requested a
`web-port` branch. This document records that scope; no additional modes are
implicitly included.

## Acceptance criteria
- A visitor can enter a name, start a single-player game and roll six dice.
- Each round has three rolls; its highest score is added at the end.
- Normal rolls score their sum; six equal dice from 1–5 score value × 10.
- Six sixes reset the accumulated score to zero. As in the original, the
  existing round maximum is retained, and added at the end of that round.
- A straight (one each of 1–6) wins immediately; reaching 100 at round end wins.
- Instructions explain scoring and controls. Keyboard and pointer controls work.
- `q`, outside text entry, stops the game and shows an exit screen, not a tab close.
- A visitor can return to the menu or restart after a win or exit.
- The interface fits a 375 px viewport without horizontal scrolling.
- The native console sources and build remain unchanged by the port.

## Technical plan
- Add an isolated `web/` CMake build, using SDL2 and Emscripten.
- Reuse the original straight/generala checks from `condiciones.cpp`.
- Keep turn state in a native-testable C++ core; expose a small browser API.
- Render dice with SDL2; use accessible HTML for menus, inputs and status.
- Verify scoring and state transitions with native CTest, then build WASM and
  smoke-test browser flows when a browser runner is available.

## Out of scope for this slice
Multiplayer, persistent ranking, simulated dice input, network play and deployment.
These are subsequent slices, not nonfunctional menu options.

## Validation evidence
- Native CTest passes: normal sums, generalas, unordered straight, a non-straight
  summing to 21, six-sixes reset behavior, three-roll rounds, victory and reset.
- Emscripten Release build emits HTML, JS and WASM; SDL renders the dice.
- Playwright against the actual WASM passes at 1280 px and 375 px: start, name
  containing q, dice pixels, keyboard roll, round completion, help preserving
  state, exit from help/gameplay, restart, and no horizontal overflow or errors.
- Desktop CMake build and the six existing terminal regression tests still pass.
- Changes to the console source files: none.
