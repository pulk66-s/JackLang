#ifndef __CL_GRAMMAR_FUNCTION_H__
#define __CL_GRAMMAR_FUNCTION_H__

#include "parsing.h"

struct function_decl_cpt {
    char *name;
    struct result *args;
    struct result *lines;
};

struct result *function_decl(struct parser *p);

#endif