/**
 * @file undoMove.cpp
 * @author Seán Rourke
 * @brief This file implements undoMove.h.
 * @date 2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "undoMove.h" 

void undoMove(Board &board, Move &move) {
    if (board.moveHistory.empty()) return;

    MoveHistory history = board.moveHistory.back();
    board.moveHistory.pop_back();

    // Restore piece positions
    board.pieces[move.from] = board.pieces[move.to]; // Move piece back
    board.pieces[move.to] = EMPTY; // Restore captured piece (if any)

    // Update bitboards for the moved piece
    Piece movedPiece = board.pieces[move.from];
    board.bitboards[movedPiece][!board.currentColour] &= ~(1ULL << move.to);
    board.bitboards[movedPiece][!board.currentColour] |= (1ULL << move.from);

    // Restore captured piece bitboard if there was one
    if (history.capturedPiece != EMPTY) {
        board.bitboards[history.capturedPiece][board.currentColour] |= (1ULL << move.to);
    }

    // Restore castling rights
    board.whiteCanCastleKingSide = history.whiteCanCastleKingSide;
    board.whiteCanCastleQueenSide = history.whiteCanCastleQueenSide;
    board.blackCanCastleKingSide = history.blackCanCastleKingSide;
    board.blackCanCastleQueenSide = history.blackCanCastleQueenSide;

    // Restore en passant square
    board.enPassantSquare = history.enPassantSquare;

    // Restore the current color
    board.currentColour = (board.currentColour == WHITE) ? BLACK : WHITE;
}