#ifndef __CL_PARSING_DEFAULT_CHOICE_H__
#define __CL_PARSING_DEFAULT_CHOICE_H__

#include "parsing/manager.h"

/**
 * @brief           The choice parser, it tries to parse the input with the left parser
 *                  if it fails, it tries with the next parser, and stops when it finds
 *                  a parser that succeeds
 * @param   parser  The parser
 * @param   funcs   The parsers to try
 * @param   size    The number of parsers to try
 * @return          The result of the first parser that succeeds, or NULL if all parsers failed
*/
struct result *ordered_choice(struct parser *parser, parser_func *funcs, size_t size);

/**
 * @brief           The sequence parser, it tries to parse all the parsers in the
 *                  Given order, if one fails, it stops and returns NULL
 * @param   parser  The parser
 * @param   funcs   The parsers to try
 * @param   size    The number of parsers to try
 * @return          The result of all the parsers, or NULL if one failed
*/
struct result *sequence(struct parser *parser, parser_func *funcs, size_t size);

#endif
