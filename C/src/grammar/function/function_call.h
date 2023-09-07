#ifndef __CL_GRAMMAR_FUNCTION_FUNCTION_CALL_H__
#define __CL_GRAMMAR_FUNCTION_FUNCTION_CALL_H__

#include "parsing.h"

struct function_call_cpt {
    char *identifier;
    struct result *args;
};

struct result *function_call(struct parser *p);

#endif