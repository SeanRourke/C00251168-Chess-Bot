/**
 * @file evaluation.h
 * @author Seán Rourke
 * @brief Evaluates the position to determine who is better, white or black.
 * @date 2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef EVALUATION_H
#define EVALUATION_H

#include "board.h"

/**
 * @brief Counts material value of each player.
 *
 * @param board The current state of the chessboard.
 * @return float The evaluation of the position.
 */
float materialCount(const Board &board);

/**
 * @brief Counts number of pieces each player has in the centre of the board,
 * 
 * @param board The current state of the chessboard.
 * @return float The evaluation of the position.
 */
float centrePresence(const Board &board);

/**
 * @brief Counts number of pieces each player has attacking the centre of the board,
 * 
 * @param board The current state of the chessboard.
 * @return float The evaluation of the position.
 */
float centreAttacks(const Board &board);


/**
 * @brief Run all heuristic functions to determine evaluation.
 *
 * @param board The current state of the chessboard.
 * @return float The evaluation of the position.
 */
float evaluation(const Board &board);

#endif