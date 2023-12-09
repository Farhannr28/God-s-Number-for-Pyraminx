#ifndef MOVES_H
#define MOVES_H

#include "pyraminx.h"
#include <array>

// moveList = {U, U', R, R', B, B', L, L'}

const std::array<std::array<short, 6>, 8> orientationUpdate = {{
    {0, 0, 1, 0, 1, 0},
    {1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1}
}};

const std::array<std::array<short, 6>, 8> permutationTransition = {{
    {2, 1, 4, 3, 0, 5},
    {4, 1, 0, 3, 2, 5},
    {0, 3, 1, 2, 4, 5},
    {0, 2, 3, 1, 4, 5},
    {0, 1, 2, 5, 3, 4},
    {0, 1, 2, 4, 5, 3},
    {5, 0, 2, 3, 4, 1},
    {1, 5, 2, 3, 4, 0}
}};

void intIntoScramble(int num, short *arr);

int scrambleIntoInt(short* arr);

int doMove(short *state, short moveNum);
#endif