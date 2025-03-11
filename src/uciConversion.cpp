/**
 * @file uciConversion.cpp
 * @author Seán Rourke
 * @brief Implements uciConversion.h
 * @date 2025
 *  
 */

#include "uciConversion.h"

void convertToUCI(Move &move){
    move.from = 'a' + (move.from % 8);
    move.from += '1' + (move.from / 8);

    move.to = 'a' + (move.to % 8);
    move.to += '1' + (move.to / 8);

    return;
}