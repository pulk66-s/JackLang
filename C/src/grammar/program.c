#include "grammar/program.h"
#include "grammar/expr.h"
#include <stdlib.h>

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
        .exprs = malloc(sizeof(struct result) * 2)
    };
    prgm->exprs[1] = NULL;
    prgm->exprs[0] = expr(p);
    return result(prgm, PROGRAM, 1);
}
