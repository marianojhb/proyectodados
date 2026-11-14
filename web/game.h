#pragma once

#include <array>

namespace dados {
using Dice = std::array<int, 6>;
enum class Phase { Rolling, RoundEnd, Won };
enum class Combination { Sum, Generala, SixSixes, Straight };

struct Result {
    int points;
    Combination combination;
};

Result evaluate(const Dice& dice);

class Game {
public:
    void reset();
    bool roll(const Dice& dice);
    bool nextRound();

    Dice dice{{1, 2, 3, 4, 5, 6}};
    Result result{0, Combination::Sum};
    Phase phase = Phase::Rolling;
    int round = 1;
    int rolls = 0;
    int total = 0;
    int best = 0;
};
} // namespace dados
