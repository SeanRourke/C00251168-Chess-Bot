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
 void makeMove(Board &board, const Move &move){
   int fromSquare = move.from;
   int toSquare = move.to;

   Piece pieceType = board.pieces[fromSquare];

   board.bitboards[pieceType][(board.currentColour == WHITE) ? WHITE : BLACK] &= ~(1ULL << fromSquare);
   board.bitboards[pieceType][(board.currentColour == WHITE) ? WHITE : BLACK] |= (1ULL << toSquare);

   board.pieces[toSquare] = pieceType;
   board.pieces[fromSquare] = EMPTY;

   if (move.promotionPiece != -1) {
      board.pieces[toSquare] = static_cast<Piece>(move.promotionPiece);
   }

   board.updateAggregateBitboards();

   board.currentColour = (board.currentColour == WHITE) ? BLACK : WHITE;
}
