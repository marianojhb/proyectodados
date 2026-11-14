#include "game.h"
#include <SDL.h>
#include <emscripten.h>
#include <cmath>
#include <random>

namespace {
dados::Game game;
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
std::mt19937 randomEngine(std::random_device{}());
int columns = 6;

void color(int r, int g, int b) { SDL_SetRenderDrawColor(renderer, r, g, b, 255); }

void roundedRect(int x, int y, int width, int height, int radius)
{
    for (int row = 0; row < height; ++row) {
        int dy = row < radius ? radius - row : (row >= height - radius ? row - (height - radius - 1) : 0);
        int inset = dy ? radius - static_cast<int>(std::sqrt(radius * radius - dy * dy)) : 0;
        SDL_RenderDrawLine(renderer, x + inset, y + row, x + width - inset - 1, y + row);
    }
}

void pip(int x, int y)
{
    for (int dy = -6; dy <= 6; ++dy) {
        int dx = static_cast<int>(std::sqrt(36 - dy * dy));
        SDL_RenderDrawLine(renderer, x - dx, y + dy, x + dx, y + dy);
    }
}

void drawDice()
{
    color(247, 242, 232);
    SDL_RenderClear(renderer);
    for (int i = 0; i < 6; ++i) {
        int x = (i % columns) * 120 + 13;
        int y = (i / columns) * 120 + 10;
        color(222, 210, 191);
        roundedRect(x + 1, y + 6, 94, 94, 15);
        color(190, 172, 149);
        roundedRect(x, y, 94, 94, 15);
        color(255, 253, 247);
        roundedRect(x + 1, y + 1, 92, 92, 14);
        color(71, 39, 64);
        int value = game.dice[i];
        if (value % 2) pip(x + 47, y + 47);
        if (value >= 2) { pip(x + 24, y + 24); pip(x + 70, y + 70); }
        if (value >= 4) { pip(x + 70, y + 24); pip(x + 24, y + 70); }
        if (value == 6) { pip(x + 24, y + 47); pip(x + 70, y + 47); }
    }
    SDL_RenderPresent(renderer);
}
} // namespace

extern "C" {
EMSCRIPTEN_KEEPALIVE void game_reset() { game.reset(); drawDice(); }
EMSCRIPTEN_KEEPALIVE void game_roll()
{
    dados::Dice values;
    std::uniform_int_distribution<int> die(1, 6);
    for (int& value : values) value = die(randomEngine);
    game.roll(values);
    drawDice();
}
EMSCRIPTEN_KEEPALIVE void game_next_round() { game.nextRound(); drawDice(); }
EMSCRIPTEN_KEEPALIVE int game_phase() { return static_cast<int>(game.phase); }
EMSCRIPTEN_KEEPALIVE int game_round() { return game.round; }
EMSCRIPTEN_KEEPALIVE int game_rolls() { return game.rolls; }
EMSCRIPTEN_KEEPALIVE int game_total() { return game.total; }
EMSCRIPTEN_KEEPALIVE int game_best() { return game.best; }
EMSCRIPTEN_KEEPALIVE int game_points() { return game.result.points; }
EMSCRIPTEN_KEEPALIVE int game_combination() { return static_cast<int>(game.result.combination); }
EMSCRIPTEN_KEEPALIVE int game_die(int index) { return index >= 0 && index < 6 ? game.dice[index] : 0; }
EMSCRIPTEN_KEEPALIVE void game_columns(int count)
{
    columns = count == 3 ? 3 : 6;
    SDL_SetWindowSize(window, columns * 120, (6 / columns) * 120);
    drawDice();
}
}

int main()
{
    // SDL must not capture document-wide keys intended for HTML form controls.
    // Browser gameplay shortcuts are handled separately by app.js.
    SDL_SetHint(SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT, "#canvas");
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;
    window = SDL_CreateWindow("Escalera o Cien", 0, 0, 720, 120, 0);
    if (!window) return 1;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) return 1;
    drawDice();
    return 0;
}
