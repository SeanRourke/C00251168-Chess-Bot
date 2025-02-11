/**
 * @file moveGeneration.h
 * @author Seán Rourke
 * @brief Defines functions for generating moves for piece types or player.
 * @date 2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef MOVE_GENERATION_H
#define MOVE_GENERATION_H

#include "board.h"
#include "move.h"
#include <vector>

/**
 * @brief Generates all legal pawn moves from a given position.
 * 
 * @param rank The rank (row) of the pawn.
 * @param file The file (column) of the pawn.
 * @param colour The colour of the pawn (WHITE or BLACK).
 * @param board The current state of the chessboard.
 * @return std::vector<Move> A list of legal moves for the pawn.
 */
std::vector<Move> generatePawnMoves(int rank, int file, Colour colour, const Board &board);

/**
 * @brief Generates all legal knight moves from a given position.
 * 
 * @param rank The rank (row) of the knight.
 * @param file The file (column) of the knight.
 * @param colour The colour of the knight (WHITE or BLACK).
 * @param board The current state of the chessboard.
 * @return std::vector<Move> A list of legal moves for the knight.
 */
std::vector<Move> generateKnightMoves(int rank, int file, Colour colour, const Board &board);

/**
 * @brief Generates all legal bishop moves from a given position.
 * 
 * @param rank The rank (row) of the bishop.
 * @param file The file (column) of the bishop.
 * @param colour The colour of the bishop (WHITE or BLACK).
 * @param board The current state of the chessboard.
 * @return std::vector<Move> A list of legal moves for the bishop.
 */
std::vector<Move> generateBishopMoves(int rank, int file, Colour colour, const Board &board);

/**
 * @brief Generates all legal rook moves from a given position.
 * 
 * @param rank The rank (row) of the rook.
 * @param file The file (column) of the rook.
 * @param colour The colour of the rook (WHITE or BLACK).
 * @param board The current state of the chessboard.
 * @return std::vector<Move> A list of legal moves for the rook.
 */
std::vector<Move> generateRookMoves(int rank, int file, Colour colour, const Board &board);

/**
 * @brief Generates all legal queen moves from a given position.
 * 
 * @param rank The rank (row) of the queen.
 * @param file The file (column) of the queen.
 * @param colour The colour of the queen (WHITE or BLACK).
 * @param board The current state of the chessboard.
 * @return std::vector<Move> A list of legal moves for the queen.
 */
std::vector<Move> generateQueenMoves(int rank, int file, Colour colour, const Board &board);

/**
 * @brief Generates all legal king moves from a given position.
 * 
 * @param rank The rank (row) of the king.
 * @param file The file (column) of the king.
 * @param colour The colour of the king (WHITE or BLACK).
 * @param board The current state of the chessboard.
 * @return std::vector<Move> A list of legal moves for the king.
 */
std::vector<Move> generateKingMoves(int rank, int file, Colour colour, const Board &board);

/**
 * @brief Generates all move for a player.
 * 
 * @param board The current state of the board.
 * @param colour The colour of the player (WHITE or BLACK).
 * @return std::vector<Move> 
 */
std::vector<Move> generateMoves(Colour colour, const Board &board);

#endif
