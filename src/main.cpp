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
    //chessBoard.printBoard();

    int depth = 4;

    // White's turn
    {
        Move bestMove;
        float bestEval = -1000000;
        std::vector<Move> moves = generateMoves(WHITE, chessBoard);
        filterIllegalMoves(moves, chessBoard, WHITE);

        for (const Move &move : moves)
        {
            Board tempBoard = chessBoard; // Create a copy
            makeMove(tempBoard, move);

            float eval = alphaBeta(tempBoard, depth, -100000, 100000, false);

            if (eval > bestEval)
            {
                bestEval = eval;
                bestMove = move;
            }
        }

        if (!moves.empty())
        {
            makeMove(chessBoard, bestMove);
            std::cout << std::endl  << "White " <<  bestMove <<  std::endl;
            //chessBoard.printBoard();
        }
        else
        {
            std::cout << "No valid moves found for WHITE." << std::endl << "Black Wins" << std::endl;
        }

    }

    std::cin.get();

    // Black's turn
    {
        Move bestMove;
        float bestEval = -1000000; // Reset bestEval for the black player's turn
        std::vector<Move> moves = generateMoves(BLACK, chessBoard);
        filterIllegalMoves(moves, chessBoard, BLACK); // Pass BLACK instead of WHITE

        for (const Move &move : moves)
        {
            Board tempBoard = chessBoard; // Create a copy
            makeMove(tempBoard, move);

            float eval = alphaBeta(tempBoard, depth, -100000, 100000, true);

            if (eval > bestEval)
            {
                bestEval = eval;
                bestMove = move;
            }
        }

        if (!moves.empty())
        {
            makeMove(chessBoard, bestMove);
            std::cout << std::endl << "Black " <<  bestMove <<  std::endl;
            //chessBoard.printBoard();
        }
        else
        {
            std::cout << "No valid moves found for BLACK." << std::endl << "White Wins" << std::endl;
        }

    }

    std::cin.get();

    // White's turn
    {
        Move bestMove;
        float bestEval = -1000000;
        std::vector<Move> moves = generateMoves(WHITE, chessBoard);
        filterIllegalMoves(moves, chessBoard, WHITE);

        for (const Move &move : moves)
        {
            Board tempBoard = chessBoard; // Create a copy
            makeMove(tempBoard, move);

            float eval = alphaBeta(tempBoard, depth, -100000, 100000, false);

            if (eval > bestEval)
            {
                bestEval = eval;
                bestMove = move;
            }
        }

        if (!moves.empty())
        {
            makeMove(chessBoard, bestMove);
            std::cout << std::endl  << "White " <<  bestMove <<  std::endl << std::endl;
            //chessBoard.printBoard();
        }
        else
        {
            std::cout << "No valid moves found for WHITE." << std::endl << "Black Wins" << std::endl;
        }

    }

    std::cin.get();

    // Black's turn
    {
        Move bestMove;
        float bestEval = -1000000; // Reset bestEval for the black player's turn
        std::vector<Move> moves = generateMoves(BLACK, chessBoard);
        filterIllegalMoves(moves, chessBoard, BLACK); // Pass BLACK instead of WHITE

        for (const Move &move : moves)
        {
            Board tempBoard = chessBoard; // Create a copy
            makeMove(tempBoard, move);

            float eval = alphaBeta(tempBoard, depth, -100000, 100000, true);

            if (eval > bestEval)
            {
                bestEval = eval;
                bestMove = move;
            }
        }

        if (!moves.empty())
        {
            makeMove(chessBoard, bestMove);
            std::cout << std::endl <<  "Black " << bestMove << std::endl << std::endl;
            //chessBoard.printBoard();
        }
        else
        {
            std::cout << "No valid moves found for BLACK." << std::endl << "White Wins" << std::endl;
        }

    }

    return 0;
}
