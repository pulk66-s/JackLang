#ifndef __CL_GRAMMAR_CONDITION_H__
#define __CL_GRAMMAR_CONDITION_H__

#include "parsing.h"

struct condition_cpt {
    char *keyword;
    struct result *cond;
    struct result *body;
    struct result *else_stmt;
};

struct result *condition(struct parser *p);

#endif
