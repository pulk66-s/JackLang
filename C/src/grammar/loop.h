#ifndef __CL_GRAMMAR_LOOP_H__
#define __CL_GRAMMAR_LOOP_H__

#include "parsing.h"

struct loop_cpt {
    char *keyword;
    struct result *cond;
    struct result *start;
    struct result *iter;
    struct result *body;
};

struct result *loop(struct parser *p);

#endif