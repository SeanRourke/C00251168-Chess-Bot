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

 #ifndef SEARCH_H
 #define SEARCH_H

 float alphaBeta(Board &board, int depth, int alpha, int beta, bool maximisingPlayer);

 #endif