/**
 * @file main.cpp
 * @author Seán Rourke
 * @brief Entry point for the chess engine.
 * @date 2025
 *
 * This file initialises the chess board and serves as the entry point for the chess bot.
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <vector>
#include "board.h"
#include "move.h"
#include "moveGeneration.h"
#include "makeMove.h"
#include "evaluation.h"
#include "undoMove.h"
#include "moveValidation.h"
#include "search.h"

/**
 * @brief Main function of the chess engine.
 *
 * This function initialises the starting position of the chessboard.
 *
 * @return int Returns 0 on successful execution.
 */
int main()
{

    Board chessBoard;        ///< Instance of the chessboard.
    chessBoard.initialise(); ///< Initialises the chessboard with the starting position.
    chessBoard.printBoard();

    Move bestMove;
    float bestEval = -1000000;
    std::vector<Move> moves = generateMoves(WHITE, chessBoard);
    filterIllegalMoves(moves, chessBoard, WHITE);
    int depth = 2;

    for (const Move &move : moves)
    {
        Board tempBoard = chessBoard; // Create a copy
        makeMove(tempBoard, move);

        int eval = alphaBeta(tempBoard, depth, -100000, 100000, true);

        if (eval > bestEval)
        {
            bestEval = eval;
            bestMove = move;
        }
    }
    // bestMove = moves[0];
    if (!moves.empty())
    {
        makeMove(chessBoard, bestMove);
    }
    else
    {
        std::cout << "No valid moves found." << std::endl;
    }

    std::cout << std::endl
              << "EVAL: " << evaluation(chessBoard) << std::endl;

    chessBoard.printBoard();

    return 0;
}