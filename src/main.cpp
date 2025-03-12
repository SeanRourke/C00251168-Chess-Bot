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
#include <string>
#include "board.h"
#include "move.h"
#include "moveGeneration.h"
#include "makeMove.h"
#include "evaluation.h"
#include "undoMove.h"
#include "moveValidation.h"
#include "search.h"
#include "uciConversion.h"

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
    // chessBoard.printBoard();

    std::vector<Move> moves = generateMoves(WHITE, chessBoard);
    std::vector<std::string> moveStrings;
    for (Move move : moves)
    {
        std::cout << "Move: " << move << std::endl;
    }

    for (Move move : moves)
    {
        std::string moveString = convertToUCI(move);
        moveStrings.push_back(moveString);
    }

    std::cout << std::endl
              << std::endl;

    for (std::string moveString : moveStrings)
    {
        std::cout << "Move: " << moveString << std::endl;
    }

    return 0;
}
