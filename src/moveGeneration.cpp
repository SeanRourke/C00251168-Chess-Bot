/**
 * @file moveGeneration.cpp
 * @author Seán Rourke
 * @brief Generates moves for each type of piece.
 * @date 2025
 *
 * Generates moves for each piece type, or vector of all moves for a player.
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "moveGeneration.h"
#include "moveValidation.h"

/**
 * @brief Generates legal moves for a pawn.
 *
 * @param rank The rank of the pawn.
 * @param file The file of the pawn.
 * @param colour The colour of the pawn (WHITE or BLACK).
 * @param board The current state of the board.
 * @return std::vector<Move> A vector of legal moves for the pawn.
 */
std::vector<Move> generatePawnMoves(int rank, int file, Colour colour, const Board &board)
{
    std::vector<Move> moves;

    int forward = (colour == WHITE) ? 1 : -1;
    int startRank = (colour == WHITE) ? 1 : 6;
    int promotionRank = (colour == WHITE) ? 7 : 0;

    Bitboard enemyPieces = (colour == WHITE) ? board.blackPieces : board.whitePieces;

    int forwardRank = rank + forward;
    if (forwardRank >= 0 && forwardRank < BOARD_SIZE)
    {
        int forwardSquare = forwardRank * BOARD_SIZE + file;
        if (!(board.allPieces & (1ULL << forwardSquare)))
        {
            if (forwardRank == promotionRank)
            {
                moves.push_back({rank * BOARD_SIZE + file, forwardSquare, QUEEN});
                moves.push_back({rank * BOARD_SIZE + file, forwardSquare, ROOK});
                moves.push_back({rank * BOARD_SIZE + file, forwardSquare, BISHOP});
                moves.push_back({rank * BOARD_SIZE + file, forwardSquare, KNIGHT});
            }
            else
            {
                moves.push_back({rank * BOARD_SIZE + file, forwardSquare});
            }

            if (rank == startRank)
            {
                int singleForwardRank = rank + forward;
                int singleForwardSquare = singleForwardRank * BOARD_SIZE + file;
                int doubleForwardRank = rank + 2 * forward;
                int doubleForwardSquare = doubleForwardRank * BOARD_SIZE + file;
                if (!(board.allPieces & (1ULL << singleForwardSquare)) &&
                    !(board.allPieces & (1ULL << doubleForwardSquare)))
                {
                    moves.push_back({rank * BOARD_SIZE + file, doubleForwardSquare});
                }
            }
        }
    }

    for (int side = -1; side <= 1; side += 2)
    {

        int captureFile = file + side;

        if (captureFile >= 0 && captureFile < BOARD_SIZE)
        {

            int captureSquare = forwardRank * BOARD_SIZE + captureFile;

            if (enemyPieces & (1ULL << captureSquare))
            {

                if (forwardRank == promotionRank)
                {

                    moves.push_back({rank * BOARD_SIZE + file, captureSquare, QUEEN});
                    moves.push_back({rank * BOARD_SIZE + file, captureSquare, ROOK});
                    moves.push_back({rank * BOARD_SIZE + file, captureSquare, BISHOP});
                    moves.push_back({rank * BOARD_SIZE + file, captureSquare, KNIGHT});
                }
                else
                {
                    moves.push_back({rank * BOARD_SIZE + file, captureSquare});
                }
            }
        }
    }

    if (board.enPassantSquare != -1)
    {
        int enPassantFile = board.enPassantSquare % BOARD_SIZE;
        int enPassantRank = board.enPassantSquare / BOARD_SIZE;
        if (abs(enPassantFile - file) == 1 && enPassantRank == forwardRank)
        {
            moves.push_back({rank * BOARD_SIZE + file, board.enPassantSquare});
        }
    }

    return moves;
}

/**
 * @brief Generates legal moves for a knight.
 *
 * @param rank The rank of the knight.
 * @param file The file of the knight.
 * @param colour The colour of the knight.
 * @param board The current state of the board.
 * @return std::vector<Move> A vector of legal moves for the knight.
 */
std::vector<Move> generateKnightMoves(int rank, int file, Colour colour, const Board &board)
{

    std::vector<Move> moves;

    int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    Bitboard friendlyPieces = (colour == WHITE) ? board.whitePieces : board.blackPieces;

    for (const auto &move : knightMoves)
    {
        int newRank = rank + move[0];
        int newFile = file + move[1];

        if (newRank >= 0 && newRank < BOARD_SIZE && newFile >= 0 && newFile < BOARD_SIZE)
        {
            int toSquare = newRank * BOARD_SIZE + newFile;

            if (friendlyPieces & (1ULL << toSquare))
            {
                continue;
            }

            moves.push_back({rank * BOARD_SIZE + file, toSquare});
        }
    }

    return moves;
}

/**
 * @brief Generates legal moves for a bishop.
 *
 * @param rank The rank of the bishop.
 * @param file The file of the bishop.
 * @param colour The colour of the bishop.
 * @param board The current state of the board.
 * @return std::vector<Move> A vector of legal moves for the bishop.
 */
std::vector<Move> generateBishopMoves(int rank, int file, Colour colour, const Board &board)
{

    std::vector<Move> moves;

    int directions[4][2] = {
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}};

    Bitboard friendlyPieces = (colour == WHITE) ? board.whitePieces : board.blackPieces;

    for (const auto &direction : directions)
    {
        int newRank = rank;
        int newFile = file;

        while (true)
        {
            newRank += direction[0];
            newFile += direction[1];

            if (newRank < 0 || newRank >= BOARD_SIZE || newFile < 0 || newFile >= BOARD_SIZE)
            {
                break;
            }

            int toSquare = newRank * BOARD_SIZE + newFile;

            if (friendlyPieces & (1ULL << toSquare))
            {
                break;
            }

            moves.push_back({rank * BOARD_SIZE + file, toSquare});

            if (board.allPieces & (1ULL << toSquare))
            {
                break;
            }
        }
    }

    return moves;
}

/**
 * @brief Generates legal moves for a rook.
 *
 * @param rank The rank of the rook.
 * @param file The file of the rook.
 * @param colour The colour of the rook.
 * @param board The current state of the board.
 * @return std::vector<Move> A vector of legal moves for the rook.
 */
std::vector<Move> generateRookMoves(int rank, int file, Colour colour, const Board &board)
{

    std::vector<Move> moves;

    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}};

    Bitboard friendlyPieces = (colour == WHITE) ? board.whitePieces : board.blackPieces;

    for (const auto &direction : directions)
    {
        int newRank = rank;
        int newFile = file;

        while (true)
        {
            newRank += direction[0];
            newFile += direction[1];

            if (newRank < 0 || newRank >= BOARD_SIZE || newFile < 0 || newFile >= BOARD_SIZE)
            {
                break;
            }

            int toSquare = newRank * BOARD_SIZE + newFile;

            if (friendlyPieces & (1ULL << toSquare))
            {
                break;
            }

            moves.push_back({rank * BOARD_SIZE + file, toSquare});

            if (board.allPieces & (1ULL << toSquare))
            {
                break;
            }
        }
    }

    return moves;
}

/**
 * @brief Generates legal moves for a queen.
 *
 * @param rank The rank of the queen.
 * @param file The file of the queen.
 * @param colour The colour of the queen.
 * @param board The current state of the board.
 * @return std::vector<Move> A vector of legal moves for the queen.
 */
std::vector<Move> generateQueenMoves(int rank, int file, Colour colour, const Board &board)
{

    std::vector<Move> moves;

    auto rookMoves = generateRookMoves(rank, file, colour, board);
    moves.insert(moves.end(), rookMoves.begin(), rookMoves.end());

    auto bishopMoves = generateBishopMoves(rank, file, colour, board);
    moves.insert(moves.end(), bishopMoves.begin(), bishopMoves.end());

    return moves;
}

/**
 * @brief Generates legal moves for a king.
 *
 * @param rank The rank of the king.
 * @param file The file of the king.
 * @param colour The colour of the king.
 * @param board The current state of the board.
 * @return std::vector<Move> A vector of legal moves for the king.
 */
std::vector<Move> generateKingMoves(int rank, int file, Colour colour, const Board &board)
{

    std::vector<Move> moves;

    int kingMoves[8][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}};

    Bitboard friendlyPieces = (colour == WHITE) ? board.whitePieces : board.blackPieces;
    Colour attacker = (colour == WHITE) ? BLACK : WHITE;

    for (const auto &move : kingMoves)
    {
        int newRank = rank + move[0];
        int newFile = file + move[1];

        if (newRank >= 0 && newRank < BOARD_SIZE && newFile >= 0 && newFile < BOARD_SIZE)
        {
            int toSquare = newRank * BOARD_SIZE + newFile;

            if (!(friendlyPieces & (1ULL << toSquare)))
            {
                if (!isSquareAttacked(toSquare, attacker, board)){
                    moves.push_back({rank * BOARD_SIZE + file, toSquare});
                }
            }
        }
    }

    if (colour == WHITE)
    {
        if (board.whiteCanCastleKingSide &&
            !(board.allPieces & ((1ULL << 5) | (1ULL << 6))) &&
            !isSquareAttacked(4, WHITE, board) &&
            !isSquareAttacked(5, WHITE, board) &&
            !isSquareAttacked(6, WHITE, board))
        {
            moves.push_back({4, 6, -1, true});
        }

        if (board.whiteCanCastleQueenSide &&
            !(board.allPieces & ((1ULL << 1) | (1ULL << 2) | (1ULL << 3))) &&
            !isSquareAttacked(4, BLACK, board) &&
            !isSquareAttacked(3, BLACK, board) &&
            !isSquareAttacked(2, BLACK, board))
        {
            moves.push_back({4, 2, -1, true});
        }
    }
    else
    {
        if (board.blackCanCastleKingSide &&
            !(board.allPieces & ((1ULL << 61) | (1ULL << 62))) &&
            !isSquareAttacked(60, WHITE, board) &&
            !isSquareAttacked(61, WHITE, board) &&
            !isSquareAttacked(62, WHITE, board))
        {
            moves.push_back({60, 62, -1, true});
        }

        if (board.blackCanCastleQueenSide &&
            !(board.allPieces & ((1ULL << 57) | (1ULL << 58) | (1ULL << 59))) &&
            !isSquareAttacked(60, BLACK, board) &&
            !isSquareAttacked(59, BLACK, board) &&
            !isSquareAttacked(58, BLACK, board))
        {
            moves.push_back({60, 58, -1, true});
        }
    }

    return moves;
}

/**
 * @brief Generates all move for a player.
 *
 * @param board The current state of the board.
 * @param colour The colour of the player.
 * @return std::vector<Move>
 */
std::vector<Move> generateMoves(Colour colour, const Board &board)
{
    std::vector<Move> moves;
    std::vector<Move> pieceMoves;

    for (int piece = PAWN; piece < MAX_PIECE_TYPE; ++piece)
    {
        Bitboard pieceBB = board.bitboards[piece][colour];

        while (pieceBB)
        {
            int square = __builtin_ctzll(pieceBB);
            pieceBB &= pieceBB - 1;

            int rank = square / 8;
            int file = square % 8;

            switch (piece)
            {
            case PAWN:
                pieceMoves = generatePawnMoves(rank, file, colour, board);
                break;
            case KNIGHT:
                pieceMoves = generateKnightMoves(rank, file, colour, board);
                break;
            case BISHOP:
                pieceMoves = generateBishopMoves(rank, file, colour, board);
                break;
            case ROOK:
                pieceMoves = generateRookMoves(rank, file, colour, board);
                break;
            case QUEEN:
                pieceMoves = generateQueenMoves(rank, file, colour, board);
                break;
            case KING:
                pieceMoves = generateKingMoves(rank, file, colour, board);
                break;
            }

            moves.insert(moves.end(), pieceMoves.begin(), pieceMoves.end());
        }
    }

    filterIllegalMoves(moves, board, colour);

    return moves;
}
