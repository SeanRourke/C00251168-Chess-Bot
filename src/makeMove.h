/**
 * @file makeMove.h
 * @author Seán Rourke
 * @brief Defines makeMove function.
 * @date 2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef MAKE_MOVE_H
#define MAKE_MOVE_H

#include "board.h"
#include "move.h"

/**
 * @brief Update bitboards to represent a move being made.
 * 
 * @param board The current state of the chessboard.
 * @param move The selected move to be made.
 */
void makeMove(Board &board, const Move &move);

#endif