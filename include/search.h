/**
 * @file search.h
 * @author Seán Rourke
 * @brief Look at potential moves to determine best move.
 * @date 2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "board.h"
#include "makeMove.h"
#include "undoMove.h"

#ifndef SEARCH_H
#define SEARCH_H

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
float alphaBeta(Board board, int depth, float alpha, float beta, bool maximisingPlayer);

#endif