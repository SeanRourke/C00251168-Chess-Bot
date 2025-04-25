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
 * @return float The evaluation of the material count.
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
 * @return float The evaluation of centre presence.
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
 * @return float The evaluation of centre attacks.
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
 * @brief Evaluates how developed each player's pieces are.
 *
 * @param board The current state of the chessboard.
 * @return float The evaluation of development.
 */
float development(const Board &board)
{

    float score = 0.0f;

    // White minor pieces starting squares
    if (!(board.bitboards[KNIGHT][WHITE] & (1ULL << 1)))
        score += 0.3f; // b1
    if (!(board.bitboards[KNIGHT][WHITE] & (1ULL << 6)))
        score += 0.3f; // g1
    if (!(board.bitboards[BISHOP][WHITE] & (1ULL << 2)))
        score += 0.3f; // c1
    if (!(board.bitboards[BISHOP][WHITE] & (1ULL << 5)))
        score += 0.3f; // f1

    // Black minor pieces starting squares
    if (!(board.bitboards[KNIGHT][BLACK] & (1ULL << 57)))
        score -= 0.3f; // b8
    if (!(board.bitboards[KNIGHT][BLACK] & (1ULL << 62)))
        score -= 0.3f; // g8
    if (!(board.bitboards[BISHOP][BLACK] & (1ULL << 58)))
        score -= 0.3f; // c8
    if (!(board.bitboards[BISHOP][BLACK] & (1ULL << 61)))
        score -= 0.3f; // f8

    return score;
}

/**
 * @brief Evaluate the safety of each player's king.
 *
 * @param board The current state of the chessboard.
 * @return float The evaluation of king safety.
 */
float kingSafety(const Board &board)
{
    float score = 0.0f;

    // White king
    int whiteKing = board.kingSquare(WHITE);
    if (board.whiteHasCastled)
    {
        score += 0.5f; // White castling
    }

    // Check white pawn shield
    if (whiteKing == 6) // g1
    {
        if (board.bitboards[PAWN][WHITE] & (1ULL << 13))
            score += 0.2f; // f2
        if (board.bitboards[PAWN][WHITE] & (1ULL << 14))
            score += 0.2f; // g2
        if (board.bitboards[PAWN][WHITE] & (1ULL << 15))
            score += 0.2f; // h2
    }
    else if (whiteKing == 2) // c1
    {
        if (board.bitboards[PAWN][WHITE] & (1ULL << 9))
            score += 0.2f; // b2
        if (board.bitboards[PAWN][WHITE] & (1ULL << 10))
            score += 0.2f; // c2
        if (board.bitboards[PAWN][WHITE] & (1ULL << 11))
            score += 0.2f; // d2
    }

    // Black king
    int blackKing = board.kingSquare(BLACK);
    if (board.blackHasCastled)
    {
        score -= 0.5f; // Black castling
    }

    // Check black pawn shield
    if (blackKing == 62) // g8
    {
        if (board.bitboards[PAWN][BLACK] & (1ULL << 53))
            score -= 0.2f; // f7
        if (board.bitboards[PAWN][BLACK] & (1ULL << 54))
            score -= 0.2f; // g7
        if (board.bitboards[PAWN][BLACK] & (1ULL << 55))
            score -= 0.2f; // h7
    }
    else if (blackKing == 58) // c8
    {
        if (board.bitboards[PAWN][BLACK] & (1ULL << 49))
            score -= 0.2f; // b7
        if (board.bitboards[PAWN][BLACK] & (1ULL << 50))
            score -= 0.2f; // c7
        if (board.bitboards[PAWN][BLACK] & (1ULL << 51))
            score -= 0.2f; // d7
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
    eval += development(board);
    eval += kingSafety(board);

    return eval;
}