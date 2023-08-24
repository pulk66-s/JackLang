#ifndef __CL_GRAMMAR_FUNCTION_H__
#define __CL_GRAMMAR_FUNCTION_H__

#include "grammar/types.h"

struct function {
    char *name;
    char *type;
};

struct result function_decl(struct packrat *p);

#endif
