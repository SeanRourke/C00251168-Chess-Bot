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

/**
 * @brief Main function of the chess engine.
 * 
 * This function initialises the starting position of the chess board.
 * 
 * @return int Returns 0 on successful execution.
 */
int main()
{

    Board chessBoard; ///< Instance of the chessboard.
    chessBoard.initialise(); ///< Initialises the chessboard with the starting position.
    //chessBoard.printBoard();
    std::vector<Move> moves = generateMoves(WHITE, chessBoard);
    for (const Move &move : moves){
        std::cout << ' ' << move << ',';
    }
    makeMove(chessBoard, moves[23]);
    chessBoard.printBoard();


    /*for (auto piece: chessBoard.pieces){
        std::cout << ' ' << piece << ',';
    }

    return 0;*/
}