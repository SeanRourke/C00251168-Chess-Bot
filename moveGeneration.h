#ifndef MOVE_GENERATION_H
#define MOVE_GENERATION_H

#include "board.h"
#include "move.h"
#include <vector>

std::vector<Move> generatePawnMoves(int rank, int file, Colour colour, const Board &board);
std::vector<Move> generateKnightMoves(int rank, int file, Colour colour, const Board &board);
std::vector<Move> generateBishopMoves(int rank, int file, Colour colour, const Board &board);
std::vector<Move> generateRookMoves(int rank, int file, Colour colour, const Board &board);
std::vector<Move> generateQueenMoves(int rank, int file, Colour colour, const Board &board);
std::vector<Move> generateKingMoves(int rank, int file, Colour colour, const Board &board);

#endif
