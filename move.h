#ifndef MOVE_H
#define MOVE_H

#include <iostream>

struct Move {
    int from;
    int to;
    int promotionPiece = -1; // Optional, default to -1 if no promotion

    friend std::ostream &operator<<(std::ostream &os, const Move &move);
};

#endif
