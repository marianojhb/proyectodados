#include "game.h"
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <string>
#include "../funciones.h"

namespace dados {
Result evaluate(const Dice& dice)
{
    for (int value : dice) {
        if (value < 1 || value > 6) throw std::invalid_argument("Dice must be 1–6");
    }
    Dice copy = dice;
    int points = std::accumulate(copy.begin(), copy.end(), 0);
    if (esEscalera(copy.data(), 6, points)) return {100, Combination::Straight};
    if (points == 36) return {0, Combination::SixSixes};
    generala(copy.data(), 6, points);
    bool equal = std::all_of(copy.begin(), copy.end(), [&](int v) { return v == copy[0]; });
    return {points, equal ? Combination::Generala : Combination::Sum};
}

void Game::reset() { *this = Game{}; }

bool Game::roll(const Dice& values)
{
    if (phase != Phase::Rolling) return false;
    Result evaluated = evaluate(values);
    dice = values;
    result = evaluated;
    ++rolls;
    if (result.combination == Combination::Straight) {
        total = 100;
        phase = Phase::Won;
        return true;
    }
    if (result.combination == Combination::SixSixes) total = 0;
    best = std::max(best, result.points);
    if (rolls == 3) {
        total += best;
        phase = total >= 100 ? Phase::Won : Phase::RoundEnd;
    }
    return true;
}

bool Game::nextRound()
{
    if (phase != Phase::RoundEnd) return false;
    ++round;
    rolls = 0;
    best = 0;
    result = {0, Combination::Sum};
    phase = Phase::Rolling;
    return true;
}
} // namespace dados
