/**
 * @file board.h
 * @author Seán Rourke
 * @brief Defines chessboard representation using bitboards.
 * @date 2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <iostream>
#include <bitset>
#include <cstdint>

using Bitboard = uint64_t; ///< Defines a bitboard as a 64 bit integer.

const int BOARD_SIZE = 8; ///< Number of ranks and files in a standard chessboard.

/**
 * @enum Piece
 * @brief Represents different types of chess pieces
 */
enum Piece
{
    PAWN,   ///< Represents a pawn.
    KNIGHT, ///< Represents a knight.
    BISHOP, ///< Represents a bishop.
    ROOK,   ///< Represents a rook.
    QUEEN,  ///< Represents a queen.
    KING,   ///< Represents a king.
    MAX_PIECE_TYPE  ///< Piece type count.
};

/**
 * @enum Colour
 * @brief Represents the colour of a chess piece.
 */
enum Colour
{
    WHITE,  ///< Represents white pieces.
    BLACK,  ///< Represents black pieces.
    MAX_COLOUR  ///< Colour count.
};

/**
 * @class Board 
 * @brief Represents a chessboard using bitboards.
 * 
 * Manages the board representation of a chessboard using bitboards.
 */
class Board
{
public:
    /**
     * @brief Stores bitboards for each piece type and colour.
     * bitboard[Piece][Colour] gives the bitboard for that piece-colour combination.
     */
    std::array<std::array<Bitboard, MAX_COLOUR>, MAX_PIECE_TYPE> bitboards = {};
    Bitboard allPieces = 0;     ///< Bitboard containing all occupied squares. 
    Bitboard whitePieces = 0;   ///< Bitboard containing all white pieces.
    Bitboard blackPieces = 0;   ///< Bitboard containing all black pieces.
    int enPassantSquare = -1;   ///< Stores location of valid en passant square (-1 if none).

    /**
     * @brief Construct a new Board object.
     */
    Board();

    /**
     * @brief Initialises the board with the standard chess starting position.
     */
    void initialise();

    /**
     * @brief Updates aggregate bitboards.
     */
    void updateAggregateBitboards();

    /**
     * @brief Prints a given bitboard to the console.
     * 
     * @param board The bitboard to be printed.
     */
    void printBitboard(Bitboard board) const;

    /**
     * @brief Prints bitboards for all pieces.
     */
    void printBoard() const;
};

#endif
