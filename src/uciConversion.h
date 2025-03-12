/**
 * @file uciConversion.h
 * @author Seán Rourke
 * @brief Converts numeric square representation to Universal Chess Interface. eg. 28 -> e4.
 * @date 2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef UCI_CONVERSION_H
#define UCI_CONVERSION_H

#include "move.h"
#include <string>

/**
 * @brief Converts the toSquare and the fromSquare of a move to UCI.
 *
 * @param move The move who's squares are being converted.
 */
std::string convertToUCI(Move &move);

#endif