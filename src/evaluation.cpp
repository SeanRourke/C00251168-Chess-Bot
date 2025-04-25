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
#include "moveValidation.h"

/**
 * @brief Counts material value of each player.
 *
 * @param board The current state of the chessboard.
 * @return float The evaluation of the position.
 */
float materialCount(const Board &board)
{
    constexpr int pieceValues[MAX_PIECE_TYPE] = {1, 3, 3, 5, 9, 10000};

    int whiteMaterial = 0, blackMaterial = 0;

    for (int piece = PAWN; piece < MAX_PIECE_TYPE; ++piece)
    {
        whiteMaterial += __builtin_popcountll(board.bitboards[piece][WHITE]) * pieceValues[piece];
        blackMaterial += __builtin_popcountll(board.bitboards[piece][BLACK]) * pieceValues[piece];
    }

    return whiteMaterial - blackMaterial; // Positive if white is better, negative if black is better
}

/**
 * @brief Counts number of pieces each player has in the centre of the board,
 * 
 * @param board The current state of the chessboard.
 * @return float The evaluation of the position.
 */
float centrePresence(const Board &board)
{
    constexpr uint64_t centerMask = (1ULL << 27) | (1ULL << 28) | (1ULL << 35) | (1ULL << 36);
    float score = 0.0f;

    for (int piece = PAWN; piece < MAX_PIECE_TYPE; ++piece)
    {
        uint64_t white = board.bitboards[piece][WHITE] & centerMask;
        uint64_t black = board.bitboards[piece][BLACK] & centerMask;

        score += 0.5f * __builtin_popcountll(white); // reward per white piece in center
        score -= 0.5f * __builtin_popcountll(black); // penalize black controlling center
    }

    return score;
}

/**
 * @brief Counts number of pieces each player has attacking the centre of the board,
 * 
 * @param board The current state of the chessboard.
 * @return float The evaluation of the position.
 */
float centreAttacks(const Board &board)
{
    constexpr int centerSquares[4] = {27, 28, 35, 36};
    float score = 0.0f;

    for (int i = 0; i < 4; ++i)
    {
        int sq = centerSquares[i];

        // If white attacks square
        if (isSquareAttacked(sq, WHITE, board))
            score += 0.3f;

        if (isSquareAttacked(sq, BLACK, board))
            score -= 0.3f;
    }

    return score;
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
    eval += centrePresence(board);
    eval += centreAttacks(board);

    return eval;
}