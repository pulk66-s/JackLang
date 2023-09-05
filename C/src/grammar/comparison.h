#ifndef __CL_GRAMMAR_COMPARISON_H__
#define __CL_GRAMMAR_COMPARISON_H__

#include "parsing.h"

struct comparison_cpt {
    char *comp;
    struct result *left;
    struct result *right;
};

struct result *comparison(struct parser *p);

#endif