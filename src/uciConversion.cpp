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

std::string convertToUCI(Move &move)
{

    std::string moveString;

    moveString += 'a' + (move.from % 8);
    moveString += '1' + (move.from / 8);

    moveString += 'a' + (move.to % 8);
    moveString += '1' + (move.to / 8);

    return moveString;
}