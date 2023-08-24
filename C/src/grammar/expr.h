#ifndef __CL_GRAMMAR_EXPR_H__
#define __CL_GRAMMAR_EXPR_H__

#include "grammar/types.h"

struct expr {
    char terminate;
    char *name;
};

struct result expr(struct packrat *p);

#endif
