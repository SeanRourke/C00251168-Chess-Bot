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
#include <sstream>
#include <chrono>
#include <thread>
#include "board.h"
#include "move.h"
#include "moveGeneration.h"
#include "makeMove.h"
#include "evaluation.h"
#include "moveValidation.h"
#include "search.h"
#include "uciConversion.h"

/**
 * @brief UCI protocol to receive move made in the lichess website and update board.
 *
 * @param chessBoard The current state of the chessboard.
 * @param input String sent by the lichess-bot api client containing the moves that have been made.
 */
void handlePosition(Board &chessBoard, const std::string &input)
{
    std::istringstream iss(input);
    std::string token;
    std::vector<std::string> moves;

    while (iss >> token)
    {
        if (token == "moves")
        {
            while (iss >> token)
            {
                moves.push_back(token);
            }
        }
    }

    if (!moves.empty())
    {
        std::string lastMove = moves.back();
        Move move = convertFromUCI(chessBoard, lastMove);
        makeMove(chessBoard, move);
    }
    return;
}

/**
 * @brief Search for best move for the bot to make using alpha beta.
 *
 * @param chessBoard The current state of the chessboard.
 * @param depth The number of moves to simulate ahead when searching.
 */
std::string findBestMove(Board &chessBoard, int depth)
{
    std::vector<Move> moves = generateMoves(chessBoard.currentColour, chessBoard);
    Move bestMove;
    bestMove = moves[0];
    if (moves.empty())
    {
        std::string bestMoveString = "(none)";
        return bestMoveString;
    }
    float bestEval = (chessBoard.currentColour == WHITE) ? -1000000 : 1000000;
    float alpha = -1000000;
    float beta = 1000000;

    for (const Move &move : moves)
    {
        Board newBoard = chessBoard;
        makeMove(newBoard, move);

        float eval = alphaBeta(newBoard, depth - 1, alpha, beta, chessBoard.currentColour == BLACK);

        if ((chessBoard.currentColour == WHITE && eval > bestEval) ||
            (chessBoard.currentColour == BLACK && eval < bestEval))
        {
            bestEval = eval;
            bestMove = move;
        }
    }
    makeMove(chessBoard, bestMove);
    std::string bestMoveString = convertToUCI(bestMove);
    return bestMoveString;
}

/**
 * @brief UCI protocol to respond when it is bot's turn to move.
 *
 * @param chessBoard The current state of the chessboard.
 * @param depth The number of moves to simulate ahead when searching.
 */
void handleGo(Board &chessBoard, int depth)
{
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    std::string bestMoveString = findBestMove(chessBoard, depth);
    std::cout << "bestmove " << bestMoveString << std::endl;
    return;
}

/**
 * @brief Main function to receive and respond to UCI commands.
 */
int main()
{

    Board chessBoard;
    chessBoard.initialise();
    // chessBoard.printBoard();
    int depth = 4;
    std::string input;
    std::cout.sync_with_stdio(false);

    while (std::getline(std::cin, input))
    {
        if (input == "uci")
        {
            std::cout << "id name Herm0ni" << std::endl;
            std::cout << "id author Sean Rourke" << std::endl;
            std::cout << "uciok" << std::endl;
        }
        else if (input == "isready")
        {
            std::cout << "readyok" << std::endl;
        }
        else if (input.rfind("position", 0) == 0)
        {
            handlePosition(chessBoard, input);
        }
        else if (input.rfind("go", 0) == 0)
        {
            handleGo(chessBoard, depth);
        }
        else if (input == "quit")
        {
            break;
        }
    }

    return 0;
}