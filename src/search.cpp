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

 float alphaBeta(Board &board, int depth, int alpha, int beta, bool maximisingPlayer){

    if (depth == 0) {
        return evaluation(board);
    }

    std::vector<Move> moves = generateMoves(board.currentColour, board);
    int bestEval = maximisingPlayer ? -1000000 : 1000000;

    if (maximisingPlayer) {

    }

 }