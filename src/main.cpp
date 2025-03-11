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

    std::vector<Move> moves = generateRookMoves(0, 7, WHITE, chessBoard);

    std::cout << std::endl << chessBoard.whiteCanCastleKingSide << std::endl;

    std::cout << moves[0];

    makeMove(chessBoard, moves[0]);

    std::vector<Move> moves2 = generateRookMoves(1, 7, WHITE, chessBoard);

    std::cout << std::endl << std::endl;

    std::cout << moves2[5];

    makeMove(chessBoard, moves2[5]);

    std::cout << std::endl << chessBoard.whiteCanCastleKingSide << std::endl;
    std::cout << std::endl << chessBoard.whiteCanCastleQueenSide << std::endl;

    
    return 0;
}
