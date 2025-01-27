// Seán Rourke
// C00251168

#include <iostream>
#include <bitset>
#include <cstdint>
#include <array>
#include <string>
#include <vector>

using Bitboard = uint64_t;

const int BOARD_SIZE = 8;

// piece types
enum Piece
{
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    MAX_PIECE_TYPE
};

// piece colours
enum Colour
{
    WHITE,
    BLACK,
    MAX_COLOUR
};

// bitboards to store board state
struct Board
{

    std::array<std::array<Bitboard, MAX_COLOUR>, MAX_PIECE_TYPE> bitboards = {};

    Bitboard allPieces = 0;
    Bitboard whitePieces = 0;
    Bitboard blackPieces = 0;
    int enPassantSquare = 41; // -1 means no en passant available

    // start position
    void initialise()
    {
        bitboards[PAWN][WHITE] = 0x000000000000FF00;
        bitboards[PAWN][BLACK] = 0x00FF000000000000;

        bitboards[ROOK][WHITE] = 0x0000000000000081;
        bitboards[ROOK][BLACK] = 0x8100000000000000;

        bitboards[KNIGHT][WHITE] = 0x0000000000000042;
        bitboards[KNIGHT][BLACK] = 0x4200000000000000;

        bitboards[BISHOP][WHITE] = 0x0000000000000024;
        bitboards[BISHOP][BLACK] = 0x2400000000000000;

        bitboards[QUEEN][WHITE] = 0x0000000000000008;
        bitboards[QUEEN][BLACK] = 0x0800000000000000;

        bitboards[KING][WHITE] = 0x0000000000000010;
        bitboards[KING][BLACK] = 0x1000000000000000;

        updateAggregateBitboards();
    }

    void updateAggregateBitboards()
    {
        whitePieces = 0;
        blackPieces = 0;

        for (int piece = 0; piece < MAX_PIECE_TYPE; ++piece)
        {
            whitePieces |= bitboards[piece][WHITE];
            blackPieces |= bitboards[piece][BLACK];
        }

        allPieces = whitePieces | blackPieces;
    }

    void printBitboard(Bitboard board) const
    {
        for (int rank = BOARD_SIZE - 1; rank >= 0; --rank)
        {
            for (int file = 0; file < BOARD_SIZE; ++file)
            {
                int square = rank * BOARD_SIZE + file;
                std::cout << ((board & (1ULL << square)) ? "1 " : ". ");
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    void printBoard() const
    {
        std::array<std::string, MAX_PIECE_TYPE> pieceSymbols = {"P", "N", "B", "R", "Q", "K"};
        std::array<std::string, MAX_COLOUR> colourPrefix = {"W", "B"};

        for (int colour = 0; colour < MAX_COLOUR; ++colour)
        {
            for (int piece = 0; piece < MAX_PIECE_TYPE; ++piece)
            {
                std::cout << colourPrefix[colour] << pieceSymbols[piece] << ":\n";
                printBitboard(bitboards[piece][colour]);
            }
        }
    }
};

// moves
struct Move
{

    int from;
    int to;
    int promotionPiece = -1; // Optional, default to -1 if no promotion

    friend std::ostream &operator<<(std::ostream &os, const Move &move)
    {
        os << "(" << move.from << ", " << move.to << ")";
        return os;
    }
};

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

    // firendly and opposition piece locations
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

int main()
{

    Board chessBoard;
    chessBoard.initialise();
    // chessBoard.printBoard();
    std::vector<Move> moves = generatePawnMoves(4, 0, WHITE, chessBoard);
    for (const Move &move : moves)
    {
        std::cout << move << " - ";
    }

    return 0;
}