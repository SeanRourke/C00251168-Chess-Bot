#include "moveGeneration.h"

/**
 * @brief Generates legal moves for a pawn.
 *
 * @param rank The rank of the pawn.
 * @param file The file of the pawn.
 * @param colour The colour of the pawn (WHITE or BLACK).
 * @param board The current state of the board.
 * @return A vector of legal moves for the pawn.
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
                int doubleForwardRank = rank + 2 * forward;
                int doubleForwardSquare = doubleForwardRank * BOARD_SIZE + file;
                if (!(board.allPieces & (1ULL << doubleForwardSquare)))
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
            moves.push_back({rank * BOARD_SIZE + file, board.enPassantSquare, PAWN});
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
 * @return A vector of legal moves for the knight.
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
 * @return A vector of legal moves for the bishop.
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
 * @return A vector of legal moves for the rook.
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
 * @return A vector of legal moves for the queen.
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
 * @return A vector of legal moves for the king.
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

    for (const auto &move : kingMoves)
    {
        int newRank = rank + move[0];
        int newFile = file + move[1];

        if (newRank >= 0 && newRank < BOARD_SIZE && newFile >= 0 && newFile < BOARD_SIZE)
        {
            int toSquare = newRank * BOARD_SIZE + newFile;

            if (!(friendlyPieces & (1ULL << toSquare)))
            {
                moves.push_back({rank * BOARD_SIZE + file, toSquare});
            }
        }
    }

    return moves;
}