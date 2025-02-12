/**
 * @file move.cpp
 * @author Seán Rourke
 * @brief Prints moves to the console.
 * @date 2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "move.h"

/**
 * @brief Overloads the << operator to print a move.
 * 
 * This function formats a Move object as (from, to) and outputs it to a stream.
 * 
 * @param os The output stream.
 * @param move The Move object to be printed.
 * @return std::ostream& The modified output stream.
 */
std::ostream &operator<<(std::ostream &os, const Move &move) {
    os << "Move(" << move.from << " -> " << move.to;
    if (move.promotionPiece != -1) os << ", Promotion: " << move.promotionPiece;
    if (move.castling) os << ", Castling";
    os << ")";
        return os;
}
