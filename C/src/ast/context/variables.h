#ifndef __CL_AST_CONTEXT_VARIABLES_H__
#define __CL_AST_CONTEXT_VARIABLES_H__

#include <stdbool.h>

struct context_var {
    char *name;
    struct context_var *next;
};

void new_context_var(char *name);
bool exists_context_var(char *name);

#endif
