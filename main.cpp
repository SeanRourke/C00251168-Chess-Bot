// Seán Rourke
// C00251168

#include <iostream>
#include <bitset>
#include <cstdint>
#include <array>
#include <string>
#include <vector>
#include "board.h"
#include "move.h"
#include "moveGeneration.h"

int main()
{

    Board chessBoard;
    chessBoard.initialise();
    //chessBoard.printBoard();
    std::vector<Move> moves = generateRookMoves(2, 1, WHITE, chessBoard);
    for (const Move &move : moves)
    {
        std::cout << move << " - ";
    }

    return 0;
}