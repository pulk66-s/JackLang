#ifndef __CL_PARSING_WORDS_NUMBERS_H__
#define __CL_PARSING_WORDS_NUMBERS_H__

#include "parsing/manager.h"

/**
 * @brief       Parse a number.
 * @details     A number is a sequence of digits.
 * @param   p   The parser.
 * @return      The result of the parsing.
*/
struct result *number(struct parser *p);

#endif
