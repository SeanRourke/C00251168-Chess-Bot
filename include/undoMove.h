/**
 * @file undoMove.h
 * @author Seán Rourke
 * @brief Updates bitboards to undo the previous move.
 * @date 2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #ifndef UNDOMOVE_H
 #define UNDOMOVE_H

 #include "move.h"
 #include "board.h"

 void undoMove(Board &board, Move &move);

 #endif