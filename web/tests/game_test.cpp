#include "game.h"
#include <iostream>
#include <stdexcept>

using namespace dados;
void check(bool condition, const char* message)
{
    if (!condition) throw std::runtime_error(message);
}

int main()
{
    check(evaluate({{1, 2, 2, 3, 4, 5}}).points == 17, "normal sum");
    for (int value = 1; value <= 5; ++value) {
        Dice dice;
        dice.fill(value);
        Result result = evaluate(dice);
        check(result.points == value * 10, "generala points");
        check(result.combination == Combination::Generala, "generala label");
    }
    check(evaluate({{6, 6, 6, 6, 6, 6}}).points == 0, "six sixes");
    check(evaluate({{6, 2, 5, 4, 1, 3}}).combination == Combination::Straight, "unordered straight");
    check(evaluate({{1, 1, 4, 4, 5, 6}}).combination == Combination::Sum, "sum 21 is not a straight");

    Game game;
    bool invalid = false;
    try { game.roll({{0, 1, 2, 3, 4, 5}}); }
    catch (const std::invalid_argument&) { invalid = true; }
    check(invalid && game.rolls == 0, "invalid dice cannot change state");
    check(!game.nextRound(), "cannot skip a round");
    for (int i = 0; i < 3; ++i) game.roll({{5, 5, 5, 5, 5, 5}});
    check(game.total == 50 && game.phase == Phase::RoundEnd, "only best roll counts");
    check(!game.roll({{1, 2, 3, 4, 5, 6}}), "round end requires explicit continue");
    check(game.nextRound() && game.round == 2 && game.best == 0 && game.rolls == 0, "next round");
    for (int i = 0; i < 3; ++i) game.roll({{5, 5, 5, 5, 5, 5}});
    check(game.total == 100 && game.phase == Phase::Won, "100 wins at round end");
    check(!game.nextRound(), "cannot continue after victory");
    game.reset();
    game.roll({{6, 2, 5, 4, 1, 3}});
    check(game.phase == Phase::Won && game.rolls == 1, "straight wins immediately");
    game.reset();
    for (int i = 0; i < 3; ++i) game.roll({{4, 4, 4, 4, 4, 4}});
    game.nextRound();
    game.roll({{3, 3, 3, 3, 3, 3}});
    game.roll({{6, 6, 6, 6, 6, 6}});
    check(game.total == 0 && game.best == 30, "six sixes resets total, retains round best");
    game.roll({{1, 1, 1, 1, 1, 1}});
    check(game.total == 30, "round best added after reset");
    game.reset();
    check(game.round == 1 && game.rolls == 0 && game.total == 0 && game.best == 0,
          "restart clears match state");
    std::cout << "All scoring and turn-state checks passed\n";
}
