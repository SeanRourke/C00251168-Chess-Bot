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

    std::vector<Move> moves = generateKingMoves(0, 4, WHITE, chessBoard);

    std::cout << chessBoard.whiteCanCastleKingSide << std::endl;

    for (Move move : moves) {
        std::cout << " - " << move;
    }

    makeMove(chessBoard, moves[0]);

    std::cout << std::endl << std::endl;

    std::vector<Move> moves2 = generateKingMoves(1, 4, WHITE, chessBoard);

    std::cout << chessBoard.whiteCanCastleKingSide << std::endl;

    for (Move move : moves2) {
        std::cout << " - " << move;
    }
    
    return 0;
}
