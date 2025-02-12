/**
 * @file moveValidation.cpp
 * @author Seán Rourke
 * @brief Implements moveValidation.h to check if a move is legal.
 * @date 2025
 *
 * Provides functionality to check if a square is attacked, used in both
 * castling and pin logic.
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "moveValidation.h"
#include "vector"
#include "move.h"
#include "moveGeneration.h"

bool isSquareAttacked(int square, Colour attacker, const Board &board)
{

    std::vector<Move> opponentMoves = generateMoves(attacker, board);
    for (const Move &move : opponentMoves)
    {
        if (move.to == square)
        {
            return true;
        }
    }
    return false;
}