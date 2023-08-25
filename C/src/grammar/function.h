#ifndef __CL_GRAMMAR_FUNCTION_H__
#define __CL_GRAMMAR_FUNCTION_H__

#include "grammar/types.h"

struct arg {
    char *type;
    char *name;
};

struct function {
    char *name;
    char *type;
    struct result *args;
    struct result *body;
};

struct result function_decl(struct packrat *p);

#endif
