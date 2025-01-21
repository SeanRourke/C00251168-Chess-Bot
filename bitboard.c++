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

enum Piece {
    PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, MAX_PIECE_TYPE
};

enum Colour {
    WHITE, BLACK, MAX_COLOUR
};

struct Board {

    std::array<std::array<Bitboard, MAX_COLOUR>, MAX_PIECE_TYPE> bitboards = {};

    Bitboard allPieces = 0;

    void initialise() {

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

        for (int piece = 0; piece < MAX_PIECE_TYPE; ++piece) {
            for (int colour = 0; colour < MAX_COLOUR; ++colour) {
                allPieces |= bitboards[piece][colour];
            }
        }
    }

    void printBitboard(Bitboard board) const {
        for (int rank = BOARD_SIZE - 1; rank >= 0; --rank) {
            for (int file = 0; file < BOARD_SIZE; ++file) {
                int square = rank * BOARD_SIZE + file;
                std::cout << ((board & (1ULL << square)) ? "1 " : ". ");
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    void printBoard() const {
        std::array<std::string, MAX_PIECE_TYPE> pieceSymbols = {"P", "N", "B", "R", "Q", "K"};
        std::array<std::string, MAX_COLOUR> colourPrefix = {"W", "B"};

        for (int colour = 0; colour < MAX_COLOUR; ++colour) {
            for (int piece = 0; piece < MAX_PIECE_TYPE; ++piece) {
                std::cout << colourPrefix[colour] << pieceSymbols[piece] << ":\n";
                printBitboard(bitboards[piece][colour]);
            }
        }
    }
};

struct Move {

    int from;
    int to;

    friend std::ostream& operator<<(std::ostream& os, const Move& move) {
        os << "(" << move.from << ", " << move.to << ")";
        return os;
    }

};

std::vector<Move> generatePawnMoves(int rank, int file, Colour colour) {
    std::vector<Move> moves;
    int direction = (colour == WHITE) ? 1 : -1;

    int newRank = rank + direction;
    if (newRank >= 0 && newRank < BOARD_SIZE) {
        moves.push_back({rank * BOARD_SIZE + file, newRank * BOARD_SIZE + file});

        if ((colour == WHITE && rank == 1) || (colour == BLACK && rank == 6)) {
            newRank += direction;
            if (newRank >= 0 && newRank < BOARD_SIZE) {
                moves.push_back({rank * BOARD_SIZE + file, newRank * BOARD_SIZE + file});
            }
        }

        for (int i = -1; i <= i; i += 2) {
            int newFile = file + i;
            if (newFile >= 0 && newFile < BOARD_SIZE) {
                moves.push_back({rank * BOARD_SIZE + file, newRank * BOARD_SIZE + newFile});
            }
        }
    }

    return moves;
}

std::vector<Move> generateKnightMoves(int rank, int file) {
    std::vector<Move> moves;
    int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (const auto& move : knightMoves) {
        int newRank = rank + move[0];
        int newFile = file + move[1];
        if (newRank >= 0 && newRank < BOARD_SIZE && newFile >= 0 && newFile < BOARD_SIZE) {
            moves.push_back({rank * BOARD_SIZE + file, newRank * BOARD_SIZE + newFile});
        }
    }
    return moves;
}

int main() {

    Board chessBoard;
    chessBoard.initialise();
    chessBoard.printBoard();
    std::vector<Move> moves = generateKnightMoves(3, 5);
    for (const Move& move : moves) {
        std::cout << move << " - ";
    }

    return 0;

}