/**
 * @file makeMove.cpp
 * @author Seán Rourke
 * @brief Updates bitboards to represent selected move.
 * @date 2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "makeMove.h"

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

   MoveHistory history;
   history.move = move;
   history.capturedPiece = board.pieces[toSquare]; // Store captured piece
   history.whiteCanCastleKingSide = board.whiteCanCastleKingSide;
   history.whiteCanCastleQueenSide = board.whiteCanCastleQueenSide;
   history.blackCanCastleKingSide = board.blackCanCastleKingSide;
   history.blackCanCastleQueenSide = board.blackCanCastleQueenSide;
   history.enPassantSquare = board.enPassantSquare;

   board.moveHistory.push_back(history); // Save the current board state

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
      if (pieceType == KING) {
         if (board.currentColour == WHITE) {
            board.whiteCanCastleKingSide = false;
            board.whiteCanCastleQueenSide = false;
         } else {
            board.blackCanCastleKingSide = false;
            board.blackCanCastleQueenSide = false;
         }
      }
      if (pieceType == KING && move.castling)
      {
         int rookFrom, rookTo;
         if (toSquare == 62) // Black queenside castling
            rookFrom = 63, rookTo = 61;
         else if (toSquare == 58) // Black kingside castling
            rookFrom = 56, rookTo = 59;
         else if (toSquare == 6) // White kingside castling
            rookFrom = 7, rookTo = 5;
         else if (toSquare == 2) // White queenside castling
            rookFrom = 0, rookTo = 3;

         board.pieces[rookFrom] = EMPTY;
         board.pieces[rookTo] = ROOK;
         board.bitboards[ROOK][board.currentColour] &= ~(1ULL << rookFrom);
         board.bitboards[ROOK][board.currentColour] |= (1ULL << rookTo);

         if (board.currentColour == WHITE) {
            board.whiteCanCastleKingSide = false;
            board.whiteCanCastleQueenSide = false;
         } else {
            board.blackCanCastleKingSide = false;
            board.blackCanCastleQueenSide = false;
         }
      }

      // Remove castling rights for a side if a rook moves
      if (pieceType == ROOK) {
         if (board.currentColour == WHITE) {
            if (fromSquare == 0 && board.whiteCanCastleKingSide) {
               board.whiteCanCastleQueenSide = false;
            } else if (fromSquare == 7 && board.whiteCanCastleQueenSide) {
               board.whiteCanCastleKingSide = false;
            }
         } else {
            if (fromSquare == 63 && board.blackCanCastleKingSide) {
               board.blackCanCastleKingSide = false;
            } else if (fromSquare == 56 && board.blackCanCastleQueenSide) {
               board.blackCanCastleQueenSide = false;
            }
         }
      }

      // Clear the original square
      board.pieces[fromSquare] = EMPTY;
   }

   // Update bitboards
   board.updateAggregateBitboards();

   // Switch turns
   board.currentColour = (board.currentColour == WHITE) ? BLACK : WHITE;
}
