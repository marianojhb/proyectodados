# Original console browser port

Status: implemented; scope approved by the user's request.

## Goal
Run the original C++ console game in a browser with its character-based layout,
colors, menus and rules, rather than the redesigned graphical web port.
Work is isolated on branch `web-terminal`.

## Acceptance criteria
- The original menu, instructions, dice graphics and game modes remain available.
- Arrow keys and Enter work; q exits immediately in menus and pause screens.
- Name/numeric entry supports actual keyboard typing and Backspace; q in a name
  is ordinary text. Browser input does not open JavaScript prompt dialogs.
- Simulated input can complete a game with a straight and show the original win.
- Exit stops execution and offers a fresh session, without closing the tab.
- The browser UI displays the original fixed-column terminal, not new game widgets.
- Native CMake builds and terminal tests continue to pass.

## Technical plan
- Emscripten + Asyncify compile all original game sources without rewriting rules.
- xterm.js renders ANSI colors/cursor positioning and forwards keyboard bytes.
- Small Emscripten-only rlutil hooks and C++ stream buffers replace blocking OS
  input/output. Native terminal implementations remain unchanged.
- Browser tests exercise actual keys, menu navigation, instructions, edited names,
  manual dice, winning, q and restart against the compiled WASM.

## Out of scope
Redesigning the console layout, changing game rules, network multiplayer, cloud
ranking and deployment. Fixed-column content may scroll horizontally on phones.

## Validation
- Emscripten Release build succeeded against all original game sources.
- Browser test passed with actual keyboard input: menus, all instruction pages,
  edited player name containing q, all six simulated dice, a straight victory,
  original ranking, two-player setup, random rolling, exit and session reload.
- Original menu/dice screenshots inspected; rendering remains character-based.
- Native CMake build and six terminal regression tests passed.
- Compiler warnings about existing variable-length arrays and unused flags in
  the original game remain; they were not refactored in this compatibility port.
