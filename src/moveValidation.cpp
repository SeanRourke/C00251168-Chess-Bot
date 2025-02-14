/**
 * @file moveValidation.cpp
 * @author Seán Rourke
 * @brief Implements moveValidation.h to check if a move is legal.
 * @date 2025
 *
 * Provides functionality to check if a square is attacked, used in both
 * castling and pin logic.
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "moveValidation.h"
#include "vector"
#include "move.h"
#include "moveGeneration.h"

bool isSquareAttacked(int square, Colour attacker, const Board &board)
{
    Colour defender = (attacker == WHITE) ? BLACK : WHITE;

    // Check for pawn attacks
    if (defender == WHITE) {
        if (square % 8 != 0){
            int left = square + 7;
            if (board.blackPieces & (1ULL << left) && board.pieces[left] == PAWN) {
                return true;
            }
        }
        if (square % 8 != 7){
            int right = square + 9;
            if (board.blackPieces & (1ULL << right) && board.pieces[right] == PAWN) {
                return true;
            }
        }
    }

    if (defender == BLACK) {
        if (square % 8 != 0){
            int left = square - 7;
            if (board.whitePieces & (1ULL << left) && board.pieces[left] == PAWN) {
                return true;
            }
        }
        if (square % 8 != 7){
            int right = square - 9;
            if (board.whitePieces & (1ULL << right) && board.pieces[right] == PAWN) {
                return true;
            }
        }
    }
    

    // Check for knight attacks
    int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for (const auto &move : knightMoves)
    {
        int newRank = square / BOARD_SIZE + move[0];
        int newFile = square % BOARD_SIZE + move[1];
        if (newRank >= 0 && newRank < BOARD_SIZE && newFile >= 0 && newFile < BOARD_SIZE)
        {
            int knightSquare = newRank * BOARD_SIZE + newFile;
            if (board.allPieces & (1ULL << knightSquare) && 
                ((defender == WHITE && board.blackPieces & (1ULL << knightSquare) && board.pieces[knightSquare] == KNIGHT) || 
                 (defender == BLACK && board.whitePieces & (1ULL << knightSquare) && board.pieces[knightSquare] == KNIGHT)))
            {
                return true; // Attacked by a knight
            }
        }
    }

    // Check for bishop and queen attacks (diagonal)
    int directionsBishop[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (const auto &direction : directionsBishop)
    {
        int newRank = square / BOARD_SIZE;
        int newFile = square % BOARD_SIZE;
        while (true)
        {
            newRank += direction[0];
            newFile += direction[1];
            if (newRank < 0 || newRank >= BOARD_SIZE || newFile < 0 || newFile >= BOARD_SIZE)
            {
                break; // Out of bounds
            }
            int newSquare = newRank * BOARD_SIZE + newFile;
            if (board.allPieces & (1ULL << newSquare))
            {
                // If a piece is found, check its type
                if ((defender == WHITE && board.blackPieces & (1ULL << newSquare)) ||
                    (defender == BLACK && board.whitePieces & (1ULL << newSquare)))
                {
                    if (board.pieces[newSquare] == BISHOP || board.pieces[newSquare] == QUEEN) {
                        return true; // Attacked by a bishop or queen
                    }
                }
                break; // Stop if a piece is blocking the path
            }
        }
    }

    // Check for rook and queen attacks (straight)
    int directionsRook[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (const auto &direction : directionsRook)
    {
        int newRank = square / BOARD_SIZE;
        int newFile = square % BOARD_SIZE;
        while (true)
        {
            newRank += direction[0];
            newFile += direction[1];
            if (newRank < 0 || newRank >= BOARD_SIZE || newFile < 0 || newFile >= BOARD_SIZE)
            {
                break; // Out of bounds
            }
            int newSquare = newRank * BOARD_SIZE + newFile;
            if (board.allPieces & (1ULL << newSquare))
            {
                // If a piece is found, check its type
                if ((defender == WHITE && board.blackPieces & (1ULL << newSquare)) ||
                    (defender == BLACK && board.whitePieces & (1ULL << newSquare)))
                {
                    if (board.pieces[newSquare] == ROOK || board.pieces[newSquare] == QUEEN) {
                        return true; // Attacked by a rook or queen
                    }
                }
                break; // Stop if a piece is blocking the path
            }
        }
    }

    // Check for king attacks (adjacent squares)
    int kingMoves[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (const auto &move : kingMoves)
    {
        int newRank = square / BOARD_SIZE + move[0];
        int newFile = square % BOARD_SIZE + move[1];
        if (newRank >= 0 && newRank < BOARD_SIZE && newFile >= 0 && newFile < BOARD_SIZE)
        {
            int kingSquare = newRank * BOARD_SIZE + newFile;
            if (board.allPieces & (1ULL << kingSquare) &&
                ((defender == WHITE && board.blackPieces & (1ULL << kingSquare) && board.pieces[kingSquare] == KING) ||
                 (defender == BLACK && board.whitePieces & (1ULL << kingSquare) && board.pieces[kingSquare] == KING)))
            {
                return true; // Attacked by a king
            }
        }
    }

    return false; // Not attacked
}

