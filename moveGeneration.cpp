#include "moveGeneration.h"

std::vector<Move> generatePawnMoves(int rank, int file, Colour colour, const Board &board)
{
    std::vector<Move> moves;

    // determine direction based on colour
    int forward = (colour == WHITE) ? 1 : -1;
    int startRank = (colour == WHITE) ? 1 : 6;
    int promotionRank = (colour == WHITE) ? 7 : 0;

    // friendly and opposition piece locatins
    Bitboard enemyPieces = (colour == WHITE) ? board.blackPieces : board.whitePieces;

    // one-square forward move
    int forwardRank = rank + forward;
    if (forwardRank >= 0 && forwardRank < BOARD_SIZE)
    {
        int forwardSquare = forwardRank * BOARD_SIZE + file;
        // square is unoccupied
        if (!(board.allPieces & (1ULL << forwardSquare)))
        {
            if (forwardRank == promotionRank)
            {
                // promotion moves
                moves.push_back({rank * BOARD_SIZE + file, forwardSquare, QUEEN});
                moves.push_back({rank * BOARD_SIZE + file, forwardSquare, ROOK});
                moves.push_back({rank * BOARD_SIZE + file, forwardSquare, BISHOP});
                moves.push_back({rank * BOARD_SIZE + file, forwardSquare, KNIGHT});
            }
            else
            {
                moves.push_back({rank * BOARD_SIZE + file, forwardSquare});
            }

            // two-square forward move (only from the start rank)
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

    // diagonal captures,  left (-1) and right (+1)
    for (int side = -1; side <= 1; side += 2)
    {

        int captureFile = file + side;

        if (captureFile >= 0 && captureFile < BOARD_SIZE)
        {

            int captureSquare = forwardRank * BOARD_SIZE + captureFile;

            // capturing an enemy piece
            if (enemyPieces & (1ULL << captureSquare))
            {

                if (forwardRank == promotionRank)
                {

                    // promotion captures
                    moves.push_back({rank * BOARD_SIZE + file, captureSquare, QUEEN});
                    moves.push_back({rank * BOARD_SIZE + file, captureSquare, ROOK});
                    moves.push_back({rank * BOARD_SIZE + file, captureSquare, BISHOP});
                    moves.push_back({rank * BOARD_SIZE + file, captureSquare, KNIGHT});
                }
                else
                {
                    // regular capture
                    moves.push_back({rank * BOARD_SIZE + file, captureSquare});
                }
            }
        }
    }

    // en Passant
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

std::vector<Move> generateKnightMoves(int rank, int file, Colour colour, const Board &board)
{

    std::vector<Move> moves;

    // knight move offsets
    int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    // friendly and opposition piece locations
    Bitboard friendlyPieces = (colour == WHITE) ? board.whitePieces : board.blackPieces;

    // iterate through possible knight moves
    for (const auto &move : knightMoves)
    {
        int newRank = rank + move[0];
        int newFile = file + move[1];

        // check if the move is within bounds
        if (newRank >= 0 && newRank < BOARD_SIZE && newFile >= 0 && newFile < BOARD_SIZE)
        {
            int toSquare = newRank * BOARD_SIZE + newFile;

            // check if the target square is occupied by a friendly piece
            if (friendlyPieces & (1ULL << toSquare))
            {
                // skip moves landing on friendly pieces
                continue;
            }

            // add the move to the list
            moves.push_back({rank * BOARD_SIZE + file, toSquare});
        }
    }

    return moves;
}

std::vector<Move> generateBishopMoves(int rank, int file, Colour colour, const Board &board)
{

    std::vector<Move> moves;

    // bishop move offsets
    int directions[4][2] = {
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}};

    // friendly and opposition piece locations
    Bitboard friendlyPieces = (colour == WHITE) ? board.whitePieces : board.blackPieces;

    // iterate through bishop moves
    for (const auto &direction : directions)
    {
        int newRank = rank;
        int newFile = file;

        while (true)
        {
            newRank += direction[0];
            newFile += direction[1];

            // check if the move is within bounds
            if (newRank < 0 || newRank >= BOARD_SIZE || newFile < 0 || newFile >= BOARD_SIZE)
            {
                break;
            }

            int toSquare = newRank * BOARD_SIZE + newFile;

            // check if the square is occupied
            if (friendlyPieces & (1ULL << toSquare))
            {
                // square is occupied by a friendly piece, stop this direction
                break;
            }

            // add the move to the list
            moves.push_back({rank * BOARD_SIZE + file, toSquare});

            // check if the square is occupied by an enemy piece
            if (board.allPieces & (1ULL << toSquare))
            {
                // stop further movement in this direction after capturing
                break;
            }
        }
    }

    return moves;
}

std::vector<Move> generateRookMoves(int rank, int file, Colour colour, const Board &board)
{

    std::vector<Move> moves;

    // rook move offsets
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}};

    // friendly and oppostion piece locations
    Bitboard friendlyPieces = (colour == WHITE) ? board.whitePieces : board.blackPieces;

    // iterate through rook moves
    for (const auto &direction : directions)
    {
        int newRank = rank;
        int newFile = file;

        while (true)
        {
            newRank += direction[0];
            newFile += direction[1];

            // check if the move is within bounds
            if (newRank < 0 || newRank >= BOARD_SIZE || newFile < 0 || newFile >= BOARD_SIZE)
            {
                break;
            }

            int toSquare = newRank * BOARD_SIZE + newFile;

            // check if the square is occupied
            if (friendlyPieces & (1ULL << toSquare))
            {
                // square is occupied by a friendly piece, stop this direction
                break;
            }

            // add the move to the list
            moves.push_back({rank * BOARD_SIZE + file, toSquare});

            // check if the square is occupied by an enemy piece
            if (board.allPieces & (1ULL << toSquare))
            {
                // stop further movement in this direction after capturing
                break;
            }
        }
    }

    return moves;
}

std::vector<Move> generateQueenMoves(int rank, int file, Colour colour, const Board &board)
{

    std::vector<Move> moves;

    // generate rook moves (straight movements)
    auto rookMoves = generateRookMoves(rank, file, colour, board);
    moves.insert(moves.end(), rookMoves.begin(), rookMoves.end());

    // generate bishop moves (diagonal movements)
    auto bishopMoves = generateBishopMoves(rank, file, colour, board);
    moves.insert(moves.end(), bishopMoves.begin(), bishopMoves.end());

    return moves;
}

std::vector<Move> generateKingMoves(int rank, int file, Colour colour, const Board &board)
{

    std::vector<Move> moves;

    // define all possible king move directions
    int kingMoves[8][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}};

    // friendly and opposition piece locations
    Bitboard friendlyPieces = (colour == WHITE) ? board.whitePieces : board.blackPieces;

    // iterate through all possible king moves
    for (const auto &move : kingMoves)
    {
        int newRank = rank + move[0];
        int newFile = file + move[1];

        // check if the new move is within bounds
        if (newRank >= 0 && newRank < BOARD_SIZE && newFile >= 0 && newFile < BOARD_SIZE)
        {
            int toSquare = newRank * BOARD_SIZE + newFile;

            // check if the square is occupied by a friendly piece
            if (!(friendlyPieces & (1ULL << toSquare)))
            {
                // add the move to the list
                moves.push_back({rank * BOARD_SIZE + file, toSquare});
            }
        }
    }

    return moves;
}