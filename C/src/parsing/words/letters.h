#ifndef __CL_PARSING_WORDS_LETTERS_H__
#define __CL_PARSING_WORDS_LETTERS_H__

#include "parsing/manager.h"
#include <stdbool.h>

/**
 * @brief       Parse an alpha character
 * @param   p   The parsing structure
 * @return      The result of the parsing
 *  - NULL if the parsing failed
 *  - A result structure if the char is an alpha character
*/
struct result *alpha(struct parser *p);

/**
 * @brief       Check if a char is an alpha character
 * @param   c   The char to check
 * @return      1 if the char is an alpha character else 0
*/
bool is_alpha(char c);

/**
 * @brief       Check if a char is a digit
 * @param   c   The char to check
 * @return      1 if the char is a digit else 0
*/
bool is_digit(char c);

/**
 * @brief       Parse a letter
 * @param   p   The parsing structure
 * @return      The result of the parsing
*/
struct result *character(struct parser *p);

#endif