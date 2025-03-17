/**
 * @file uciConversion.cpp
 * @author Seán Rourke
 * @brief Implements uciConversion.h
 * @date 2025
 * 
 * Converts numeric square representation to Universal Chess Interface. eg. 28 -> e4.
 *
 */

#include "uciConversion.h"

/**
 * @brief Converts a move to UCI notation.
 *
 * @param move The move who's squares are being converted.
 */
std::string convertToUCI(Move &move)
{

    std::string moveString;

    moveString += 'a' + (move.from % 8);
    moveString += '1' + (move.from / 8);

    moveString += 'a' + (move.to % 8);
    moveString += '1' + (move.to / 8);

    if (move.promotionPiece == QUEEN) {
        moveString += "=q";
    } else if (move.promotionPiece == ROOK) {
        moveString += "=r";
    } else if (move.promotionPiece == BISHOP) {
        moveString += "=b";
    } else if (move.promotionPiece == KNIGHT) {
        moveString += "=n";
    }

    return moveString;
}

/**
 * @brief Converts a move from UCI notation to numerical representation.
 * 
 * @param moveString The move who's squares are being converted.
 */
Move convertFromUCI(std::string &moveString) {
    if (moveString.length() < 4 || moveString.length() > 6) {
        throw std::invalid_argument("Invalid UCI move string");
    }

    Move move;
    move.from = (moveString[1] - '1') * 8 + (moveString[0] - 'a'); // Convert from UCI to index
    move.to = (moveString[3] - '1') * 8 + (moveString[2] - 'a');   // Convert to UCI to index
    move.promotionPiece = -1; // Default to no promotion

    // Check for promotion
    if (moveString.length() == 5 || moveString.length() == 6) {
        if (moveString[4] == '=') {
            if (moveString.length() == 6) {
                switch (moveString[5]) {
                    case 'q': move.promotionPiece = QUEEN; break;
                    case 'r': move.promotionPiece = ROOK; break;
                    case 'b': move.promotionPiece = BISHOP; break;
                    case 'n': move.promotionPiece = KNIGHT; break;
                    default: throw std::invalid_argument("Invalid promotion piece");
                }
            } else {
                throw std::invalid_argument("Invalid UCI move string");
            }
        }
    }

    return move;
}