/**
 * @file evaluation.cpp
 * @author Seán Rourke
 * @brief Implements evaluation.h to determine who is better, white or black.
 * @date 2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "evaluation.h"

/**
 * @brief Counts material value of each player.
 *
 * @param board The current state of the chessboard;
 * @return float The evaluation of the position.
 */
float materialCount(const Board &board)
{
    constexpr int pieceValues[MAX_PIECE_TYPE] = {1, 3, 3, 5, 9, 1000}; // Ignore king

    int whiteMaterial = 0, blackMaterial = 0;

    for (int piece = PAWN; piece < KING; ++piece)
    { // Exclude king
        whiteMaterial += __builtin_popcountll(board.bitboards[piece][WHITE]) * pieceValues[piece];
        blackMaterial += __builtin_popcountll(board.bitboards[piece][BLACK]) * pieceValues[piece];
    }

    return whiteMaterial - blackMaterial; // Positive if white is better, negative if black is better
}

/**
 * @brief Run all heuristic functions to determine evaluation.
 *
 * @param board The current state of the chessboard.
 * @return float The evaluation of the position.
 */
float evaluation(const Board &board)
{
    float eval = 0.0;

    eval += materialCount(board);

    return eval;
}