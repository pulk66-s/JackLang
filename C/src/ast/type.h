#ifndef __CL_AST_TYPE_H__
#define __CL_AST_TYPE_H__

#include "grammar.h"

enum type_ast {
    UNKNOWN_TYPE_AST,
    INT_TYPE_AST
};

enum type_ast type_ast(char *type);

#endif