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

   board.bitboards[pieceType][(board.currentColour == WHITE) ? WHITE : BLACK] &= ~(1ULL << fromSquare);

   if (move.promotionPiece != -1)
   {
      Piece promotedPiece = static_cast<Piece>(move.promotionPiece);

      board.bitboards[PAWN][board.currentColour] &= ~(1ULL << fromSquare);

      board.pieces[toSquare] = promotedPiece;

      board.bitboards[promotedPiece][board.currentColour] |= (1ULL << toSquare);
   }
   else
   {
      if (pieceType == PAWN && toSquare == board.enPassantSquare)
      {
         int capturedPawnSquare = toSquare + ((board.currentColour == WHITE) ? -8 : 8);
         board.pieces[capturedPawnSquare] = EMPTY;
         board.bitboards[PAWN][!board.currentColour] &= ~(1ULL << capturedPawnSquare);
      }

      board.bitboards[pieceType][board.currentColour] |= (1ULL << toSquare);
      board.pieces[toSquare] = pieceType;

      if (pieceType == KING && abs(fromSquare - toSquare) == 2)
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
   }

   Piece capturedPiece = board.pieces[toSquare];
   if (capturedPiece != EMPTY)
   {
      board.bitboards[capturedPiece][!board.currentColour] &= ~(1ULL << toSquare);
   }

   board.pieces[fromSquare] = EMPTY;

   board.updateAggregateBitboards();

   board.currentColour = (board.currentColour == WHITE) ? BLACK : WHITE;
}
