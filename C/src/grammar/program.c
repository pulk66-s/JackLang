#include "grammar/program.h"
#include "grammar/expr.h"
#include "grammar/operation.h"
#include "parsing.h"
#include <stdlib.h>

static struct result *program_expression(struct parser *p)
{
    return zero_or_more(p, primary_expression);
}

/**
 * @brief       Parse a program
 * @details     A program contains many expressions
 * @param   p   The parser
 * @return      The result of the parsing
*/
struct result *program(struct parser *p)
{
    struct program_cpt *prgm = malloc(sizeof(struct program_cpt));

    *prgm = (struct program_cpt) {
        .exprs = malloc(sizeof(struct result))
    };
    prgm->exprs = program_expression(p);
    printf("Program: %d\n", prgm->exprs->size);
    return result(prgm, PROGRAM, 1);
}
