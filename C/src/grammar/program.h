#ifndef __CL_GRAMMAR_PROGRAM_H__
#define __CL_GRAMMAR_PROGRAM_H__

#include "parsing/manager.h"

struct program_cpt {
    struct result *exprs;
};

/**
 * @brief       Parse a program
 * @details     A program contains many expressions
 * @param   p   The parser
 * @return      The result of the parsing
*/
struct result *program(struct parser *p);

#endif
