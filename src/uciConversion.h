/**
 * @file uciConversion.h
 * @author Seán Rourke
 * @brief Convert numeric square value to UCI
 * @date 2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef UCI_CONVERSION_H
#define UCI_CONVERSION_H

#include "move.h"

/**
 * @brief Converts the toSquare and the fromSquare of a move to UCI.
 * 
 * @param move The move who's squares are being converted.
 */
void convertToUCI(Move &move);

#endif