/**
 * @file board.cpp
 * @author Seán Rourke
 * @brief Implements the board class for chessboard representation using bitboards.
 * @date 2025
 *
 * This file implements board.h and sets up the chessboard with the standard
 * chess starting position.
 *
 * It also updates the bitboards when a move is made.
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "board.h"

/**
 * @brief Construct a new Board:: Board object and initialises it.
 *
 */
Board::Board() { initialise(); }

/**
 * @brief Initialises the board to the standard chess starting position.
 *
 * This function sets up the bitboards for all pieces and colours
 * according to the standard chess starting position.
 */
void Board::initialise()
{
    bitboards[PAWN][WHITE] = 0x000000000000FF00;
    bitboards[PAWN][BLACK] = 0x00FF000000000000;

    bitboards[ROOK][WHITE] = 0x0000000000000081;
    bitboards[ROOK][BLACK] = 0x8100000000000000;

    bitboards[KNIGHT][WHITE] = 0x0000000000000042;
    bitboards[KNIGHT][BLACK] = 0x4200000000000000;

    bitboards[BISHOP][WHITE] = 0x0000000000000024;
    bitboards[BISHOP][BLACK] = 0x2400000000000000;

    bitboards[QUEEN][WHITE] = 0x0000000000000008;
    bitboards[QUEEN][BLACK] = 0x0800000000000000;

    bitboards[KING][WHITE] = 0x0000000000000010;
    bitboards[KING][BLACK] = 0x1000000000000000;

    pieces.fill(EMPTY);

    for (int file = 0; file < BOARD_SIZE; ++file)
    {
        pieces[file + 8] = PAWN;
        pieces[file + 48] = PAWN;
    }

    pieces[0] = ROOK;
    pieces[7] = ROOK;
    pieces[56] = ROOK;
    pieces[63] = ROOK;

    pieces[1] = KNIGHT;
    pieces[6] = KNIGHT;
    pieces[57] = KNIGHT;
    pieces[62] = KNIGHT;

    pieces[2] = BISHOP;
    pieces[5] = BISHOP;
    pieces[58] = BISHOP;
    pieces[61] = BISHOP;

    pieces[3] = QUEEN;
    pieces[4] = KING;
    pieces[59] = QUEEN;
    pieces[60] = KING;

    whiteCanCastleKingSide = true;
    whiteCanCastleQueenSide = true;
    blackCanCastleKingSide = true;
    blackCanCastleQueenSide = true;

    updateAggregateBitboards();
}

/**
 * @brief Updates the aggregate bitboards for all pieces.
 *
 * This function recalculates 'allPieces', 'whitePieces', and 'blackPieces'
 * by combining the bitboards of the individual pieces.
 */
void Board::updateAggregateBitboards()
{
    whitePieces = 0;
    blackPieces = 0;
    allPieces = 0;

    pieces.fill(EMPTY);

    for (int piece = 0; piece < MAX_PIECE_TYPE; ++piece)
    {
        for (int colour = 0; colour < MAX_COLOUR; ++colour)
        {
            Bitboard bitboard = bitboards[piece][colour];

            if (colour == WHITE)
            {
                whitePieces |= bitboard;
            }
            else
            {
                blackPieces |= bitboard;
            }

            while (bitboard)
            {
                int square = __builtin_ctzll(bitboard);
                pieces[square] = static_cast<Piece>(piece);
                bitboard &= bitboard - 1;
            }
        }
    }
}

/**
 * @brief Prints a given bitboard in and 8x8 grid.
 *
 * @param board The bitboard to be printed.
 */
void Board::printBitboard(Bitboard board) const
{
    for (int rank = BOARD_SIZE - 1; rank >= 0; --rank)
    {
        for (int file = 0; file < BOARD_SIZE; ++file)
        {
            int square = rank * BOARD_SIZE + file;
            std::cout << ((board & (1ULL << square)) ? "1 " : ". ");
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

/**
 * @brief Prints each bitboard, showing piece placement.
 *
 * This function iterates through each piece type and colour,
 * displaying the bitboard represention of their position.
 */
void Board::printBoard() const
{
    std::array<std::string, MAX_PIECE_TYPE> pieceSymbols = {"P", "N", "B", "R", "Q", "K"};
    std::array<std::string, MAX_COLOUR> colourPrefix = {"W", "B"};

    for (int colour = 0; colour < MAX_COLOUR; ++colour)
    {
        for (int piece = 0; piece < MAX_PIECE_TYPE; ++piece)
        {
            std::cout << colourPrefix[colour] << pieceSymbols[piece] << ":\n";
            printBitboard(bitboards[piece][colour]);
        }
    }
}