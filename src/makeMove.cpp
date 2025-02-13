/**
 * @file makeMove.cpp
 * @author Seán Rourke
 * @brief Updates bitboards to represent selected move.
 * @date 2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "board.h"
#include "move.h"

/**
 * @brief Update bitboards to represent a move being made.
 *
 * @param board The current state of the chessboard.
 * @param move The selected move to be made.
 */
void makeMove(Board &board, const Move &move)
{
   int fromSquare = move.from;
   int toSquare = move.to;

   Piece pieceType = board.pieces[fromSquare];

   // Remove the piece from its original position in the bitboard
   board.bitboards[pieceType][board.currentColour] &= ~(1ULL << fromSquare);

   // Handle promotions
   if (move.promotionPiece != -1)
   {
      Piece promotedPiece = static_cast<Piece>(move.promotionPiece);
      board.bitboards[PAWN][board.currentColour] &= ~(1ULL << fromSquare);
      board.pieces[toSquare] = promotedPiece;
      board.bitboards[promotedPiece][board.currentColour] |= (1ULL << toSquare);
   }
   else
   {
      // Handle captures
      Piece capturedPiece = board.pieces[toSquare];
      if (capturedPiece != EMPTY)
      {
         board.bitboards[capturedPiece][!board.currentColour] &= ~(1ULL << toSquare);
      }

      // Handle en passant
      if (pieceType == PAWN && toSquare == board.enPassantSquare)
      {
         int capturedPawnSquare = toSquare + ((board.currentColour == WHITE) ? -8 : 8);
         board.pieces[capturedPawnSquare] = EMPTY;
         board.bitboards[PAWN][!board.currentColour] &= ~(1ULL << capturedPawnSquare);
      }

      // Move the piece to its new position
      board.pieces[toSquare] = pieceType;
      board.bitboards[pieceType][board.currentColour] |= (1ULL << toSquare);

      // Set the enPassantSquare for two-square pawn moves
      if (pieceType == PAWN && (fromSquare + 16 == toSquare || fromSquare - 16 == toSquare))
      {
         board.enPassantSquare = (board.currentColour == WHITE) ? toSquare - 8 : toSquare + 8;
      }
      else
      {
         // Clear enPassantSquare for any other move
         board.enPassantSquare = -1;
      }

      // Handle castling
      if (pieceType == KING && move.castling)
      {
         int rookFrom, rookTo;
         if (toSquare == 62) // White kingside castling
            rookFrom = 63, rookTo = 61;
         else if (toSquare == 58) // White queenside castling
            rookFrom = 56, rookTo = 59;
         else if (toSquare == 6) // Black kingside castling
            rookFrom = 7, rookTo = 5;
         else if (toSquare == 2) // Black queenside castling
            rookFrom = 0, rookTo = 3;

         Piece rook = board.pieces[rookFrom];
         board.pieces[rookFrom] = EMPTY;
         board.pieces[rookTo] = rook;
         board.bitboards[rook][board.currentColour] &= ~(1ULL << rookFrom);
         board.bitboards[rook][board.currentColour] |= (1ULL << rookTo);
         
      }

      // Clear the original square
      board.pieces[fromSquare] = EMPTY;

      // Update bitboards
      board.updateAggregateBitboards();

      // Switch turns
      board.currentColour = (board.currentColour == WHITE) ? BLACK : WHITE;
   }
}
