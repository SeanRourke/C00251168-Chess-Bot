/**
 * @file search.cpp
 * @author Seán Rourke
 * @brief This file implements search.h.
 * @date 2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <vector>
#include "search.h"
#include "evaluation.h"
#include "moveGeneration.h"

/**
 * @brief Performs the Alpha-Beta pruning search algorithm to find the best move evaluation.
 *
 * @param board The current state of the chessboard.
 * @param depth How deep to look down the tree.
 * @param alpha The best score the maximising player can guarantee.
 * @param beta The best score the minimising player can guarentee.
 * @param maximisingPlayer Whether the current player is the maximising or minimising player.
 * @return float The best evaluation score found.
 */
float alphaBeta(Board board, int depth, float alpha, float beta, bool maximisingPlayer)
{
    if (depth == 0)
    {
        return evaluation(board);
    }

    std::vector<Move> moves = generateMoves(board.currentColour, board);

    if (maximisingPlayer)
    {
        float maxEval = -1000000;

        for (const Move &move : moves)
        {
            Board newBoard = board;   // Create a copy of the board
            makeMove(newBoard, move); // Apply move to new board

            float eval = alphaBeta(newBoard, depth - 1, alpha, beta, false);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);

            if (beta <= alpha)
                break; // Alpha-beta pruning
        }
        return maxEval;
    }
    else
    {
        float minEval = 1000000;

        for (const Move &move : moves)
        {
            Board newBoard = board;   // Create a copy of the board
            makeMove(newBoard, move); // Apply move to new board

            float eval = alphaBeta(newBoard, depth - 1, alpha, beta, true);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);

            if (beta <= alpha)
                break; // Alpha-beta pruning
        }
        return minEval;
    }
}