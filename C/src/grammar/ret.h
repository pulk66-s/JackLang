#ifndef __CL_GRAMMAR_RET_H__
#define __CL_GRAMMAR_RET_H__

#include "parsing.h"

struct return_cpt {
    char *keyword;
    struct result *expr;
};

/**
 * @brief       Parse a return statement
 * @param   p   Parser object
 * @return      Result object
*/
struct result *ret(struct parser *p);

#endif
