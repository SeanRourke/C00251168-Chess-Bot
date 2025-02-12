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

bool isSquareAttacked(int square, Colour attacker, const Board &board) {
    Colour defender = (attacker == WHITE) ? BLACK : WHITE;

    // Check for pawn attacks
    int pawnDirection = (defender == WHITE) ? -1 : 1;
    int attackLeft = square + (pawnDirection * BOARD_SIZE) - 1;
    int attackRight = square + (pawnDirection * BOARD_SIZE) + 1;

    if (board.allPieces & (1ULL << attackLeft) && (board.blackPieces & (1ULL << attackLeft) || board.whitePieces & (1ULL << attackLeft))) {
        return true; // Attacked by a pawn
    }
    if (board.allPieces & (1ULL << attackRight) && (board.blackPieces & (1ULL << attackRight) || board.whitePieces & (1ULL << attackRight))) {
        return true; // Attacked by a pawn
    }

    // Check for knight attacks
    int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for (const auto &move : knightMoves) {
        int newRank = square / BOARD_SIZE + move[0];
        int newFile = square % BOARD_SIZE + move[1];
        if (newRank >= 0 && newRank < BOARD_SIZE && newFile >= 0 && newFile < BOARD_SIZE) {
            int knightSquare = newRank * BOARD_SIZE + newFile;
            if (board.allPieces & (1ULL << knightSquare) && (board.blackPieces & (1ULL << knightSquare) || board.whitePieces & (1ULL << knightSquare))) {
                return true; // Attacked by a knight
            }
        }
    }

    // Check for bishop and queen attacks (diagonal)
    int directionsBishop[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (const auto &direction : directionsBishop) {
        int newRank = square / BOARD_SIZE;
        int newFile = square % BOARD_SIZE;
        while (true) {
            newRank += direction[0];
            newFile += direction[1];
            if (newRank < 0 || newRank >= BOARD_SIZE || newFile < 0 || newFile >= BOARD_SIZE) {
                break; // Out of bounds
            }
            int newSquare = newRank * BOARD_SIZE + newFile;
            if (board.allPieces & (1ULL << newSquare)) {
                // If a piece is found, check its type
                if ((board.blackPieces & (1ULL << newSquare) && attacker == WHITE) ||
                    (board.whitePieces & (1ULL << newSquare) && attacker == BLACK)) {
                    return true; // Attacked by bishop or queen
                }
                break; // Stop if a piece is blocking the path
            }
        }
    }

    // Check for rook and queen attacks (straight)
    int directionsRook[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (const auto &direction : directionsRook) {
        int newRank = square / BOARD_SIZE;
        int newFile = square % BOARD_SIZE;
        while (true) {
            newRank += direction[0];
            newFile += direction[1];
            if (newRank < 0 || newRank >= BOARD_SIZE || newFile < 0 || newFile >= BOARD_SIZE) {
                break; // Out of bounds
            }
            int newSquare = newRank * BOARD_SIZE + newFile;
            if (board.allPieces & (1ULL << newSquare)) {
                // If a piece is found, check its type
                if ((board.blackPieces & (1ULL << newSquare) && attacker == WHITE) ||
                    (board.whitePieces & (1ULL << newSquare) && attacker == BLACK)) {
                    return true; // Attacked by rook or queen
                }
                break; // Stop if a piece is blocking the path
            }
        }
    }

    // Check for king attacks (adjacent squares)
    int kingMoves[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (const auto &move : kingMoves) {
        int newRank = square / BOARD_SIZE + move[0];
        int newFile = square % BOARD_SIZE + move[1];
        if (newRank >= 0 && newRank < BOARD_SIZE && newFile >= 0 && newFile < BOARD_SIZE) {
            int kingSquare = newRank * BOARD_SIZE + newFile;
            if (board.allPieces & (1ULL << kingSquare) && (board.blackPieces & (1ULL << kingSquare) || board.whitePieces & (1ULL << kingSquare))) {
                return true; // Attacked by a king
            }
        }
    }

    return false; // Not attacked
}
