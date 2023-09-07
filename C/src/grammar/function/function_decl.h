#ifndef __CL_GRAMMAR_FUNCTION_DECL_H__
#define __CL_GRAMMAR_FUNCTION_DECL_H__

#include "parsing.h"

struct function_arg_decl_cpt {
    char *type;
    char *name;
};

struct function_decl_cpt {
    char *type;
    char *name;
    struct function_arg_decl_cpt **args;
    struct result *lines;
};

struct result *function_decl(struct parser *p);

#endif