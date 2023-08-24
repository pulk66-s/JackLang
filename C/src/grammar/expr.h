#ifndef __CL_GRAMMAR_EXPR_H__
#define __CL_GRAMMAR_EXPR_H__

#include "grammar/types.h"

struct expr {
    struct result *data;
    char terminate;
};

struct result expr(struct packrat *p);

#endif
