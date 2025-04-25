/**
 * @file moveValidation.h
 * @author Seán Rourke
 * @brief Checks if a move is legal.
 * @date 2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef MOVEVALIDATION_H
#define MOVEVALIDATION_H

#include <algorithm>
#include "board.h"
#include "move.h"

/**
 * @brief
 *
 * @param square The square being checked for attacks.
 * @param attacker The colour of the attacking player.
 * @param board The current state of the chessboard.
 * @return true If the square is attacked.
 * @return false If the square is not attacked.
 */
bool isSquareAttacked(int square, Colour attacker, const Board &board);

/**
 * @brief Filters out moves that would leave the moving player's king in check.
 *
 * @param moves Unfiltered generated moves.
 * @param board The current state of the chessboard.
 * @param colour The player making the move.
 */
void filterIllegalMoves(std::vector<Move> &moves, const Board &board, Colour colour);

#endif