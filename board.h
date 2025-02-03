#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <iostream>
#include <bitset>
#include <cstdint>

using Bitboard = uint64_t;

const int BOARD_SIZE = 8;

// piece types
enum Piece
{
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    MAX_PIECE_TYPE
};

// piece colours
enum Colour
{
    WHITE,
    BLACK,
    MAX_COLOUR
};

class Board
{
public:
    std::array<std::array<Bitboard, MAX_COLOUR>, MAX_PIECE_TYPE> bitboards = {};
    Bitboard allPieces = 0;
    Bitboard whitePieces = 0;
    Bitboard blackPieces = 0;
    int enPassantSquare = -1;

    Board(); // Constructor

    void initialise();
    void updateAggregateBitboards();
    void printBitboard(Bitboard board) const;
    void printBoard() const;
};

#endif
