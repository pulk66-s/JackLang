#ifndef __CL_PARSING_WORDS_WORDS_H__
#define __CL_PARSING_WORDS_WORDS_H__

#include "parsing/manager.h"

/**
 * @brief       Parse a word.
 * @details     A word is a sequence of alpha characters that are not whitespace.
 * @param   p   The parser.
 * @return      The result of the parsing.
*/
struct result *alpha_word(struct parser *p);

#endif