#ifndef __CL_GRAMMAR_OPERANDS_BASIC_H__
#define __CL_GRAMMAR_OPERANDS_BASIC_H__

#include "grammar/types.h"

struct operation {
    char operand;
    struct result *left;
    struct result *right;
};

struct result operation(struct packrat *p);

#endif
