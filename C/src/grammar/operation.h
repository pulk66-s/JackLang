#ifndef __CL_GRAMMAR_OPERATION_H__
#define __CL_GRAMMAR_OPERATION_H__

#include "parsing/manager.h"

struct operation_cpt {
    char operand;
    struct result *left;
    struct result *right;
};

struct result *operation(struct parser *p);

#endif