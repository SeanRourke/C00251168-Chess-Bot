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
 
     // Check if the move was a promotion
     bool wasPromotion = move.promotionPiece != EMPTY;
 
     // If the move was a promotion, restore the pawn
     if (wasPromotion) {
         // Restore the original pawn at 'from' position
         board.pieces[move.from] = PAWN;  // Revert to pawn
 
         // Update bitboards: remove the promoted piece and restore the pawn
         board.bitboards[move.promotionPiece][board.currentColour] &= ~(1ULL << move.to);
         board.bitboards[PAWN][board.currentColour] |= (1ULL << move.from);
     } else {
         // Restore piece positions for non-promotion moves
         board.pieces[move.from] = board.pieces[move.to]; // Move piece back
         board.pieces[move.to] = EMPTY; // Restore the original square to empty
 
         // Update bitboards for the moved piece
         Piece movedPiece = board.pieces[move.from];
         board.bitboards[movedPiece][board.currentColour] &= ~(1ULL << move.to);
         board.bitboards[movedPiece][board.currentColour] |= (1ULL << move.from);
     }
 
     // Restore captured piece bitboard if there was one
     if (history.capturedPiece != EMPTY) {
         board.pieces[move.to] = history.capturedPiece; // Restore the captured piece
         board.bitboards[history.capturedPiece][!board.currentColour] |= (1ULL << move.to); // Add captured piece back to the bitboard
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
 