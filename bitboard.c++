// Seán Rourke
// C00251168

#include <iostream>
#include <bitset>
#include <cstdint>

using Bitboard = uint64_t;
using namespace std;

struct Board {
    Bitboard whitePawns   = 0x000000000000FF00;
    Bitboard blackPawns   = 0x00FF000000000000;
    Bitboard whiteKnights = 0x0000000000000042;
    Bitboard blackKnights = 0x4200000000000000;
    Bitboard whiteBishops = 0x0000000000000024;
    Bitboard blackBishops = 0x2400000000000000;
    Bitboard whiteRooks   = 0x0000000000000081;
    Bitboard blackRooks   = 0x8100000000000000;
    Bitboard whiteQueens  = 0x0000000000000008;
    Bitboard blackQueens  = 0x0800000000000000;
    Bitboard whiteKing    = 0x0000000000000010;
    Bitboard blackKing    = 0x1000000000000000;
};

void printBitboard(const Bitboard &board) {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;
            std::cout << ((board & (1ULL << square)) ? "1 " : ". ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {

    Board chessBoard;

    std::cout << "White Pawns" << endl;
    printBitboard(chessBoard.whitePawns);
    std::cout << "White Knights" << endl;
    printBitboard(chessBoard.whiteKnights);
    std::cout << "White Bishops" << endl;
    printBitboard(chessBoard.whiteBishops);
    std::cout << "White Rooks" << endl;
    printBitboard(chessBoard.whiteRooks);
    std::cout << "White Queens" << endl;
    printBitboard(chessBoard.whiteQueens);
    std::cout << "White King" << endl;
    printBitboard(chessBoard.whiteKing);
    std::cout << "Black Pawns" << endl;
    printBitboard(chessBoard.blackPawns);
    std::cout << "Black Knights" << endl;
    printBitboard(chessBoard.blackKnights);
    std::cout << "Black Bishops" << endl;
    printBitboard(chessBoard.blackBishops);
    std::cout << "Black Rooks" << endl;
    printBitboard(chessBoard.blackRooks);
    std::cout << "Black Queens" << endl;
    printBitboard(chessBoard.blackQueens);
    std::cout << "Black King" << endl;
    printBitboard(chessBoard.blackKing);
    return 0;

}