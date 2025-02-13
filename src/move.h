/**
 * @file move.h
 * @author Seán Rourke
 * @brief Defines move structure.
 * @date 2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include "board.h"

/**
 * @struct Move
 * @brief Represents a chess move.
 *
 * This structure stores the starting and ending squares of a move.
 * It also includes an optional promotion piece filed for pawn promotions.
 */
struct Move
{
    int from;                ///< The starting square of the move (0-63).
    int to;                  ///< The ending square of the move (0-63).
    int promotionPiece = -1; ///< The promoted piece type (if applicable, otherwise -1).
    bool castling = false;

    /**
     * @brief Overloads the << operator to print a move.
     * @param os The output stream.
     * @param move The move to be printed.
     * @return std::ostream& The output stream with the move formatted.
     */
    friend std::ostream &operator<<(std::ostream &os, const Move &move);
};

struct MoveHistory
{
    Move move;
    Piece capturedPiece;
    bool whiteCanCastleKingSide;
    bool whiteCanCastleQueenSide;
    bool blackCanCastleKingSide;
    bool blackCanCastleQueenSide;
    int enPassantSquare;
};

#endif
