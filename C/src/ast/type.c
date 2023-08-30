#include "ast/type.h"
#include <string.h>

enum type_ast type_ast(char *type)
{
    if (strcmp(type, "int") == 0) {
        return INT_TYPE_AST;
    }
    return UNKNOWN_TYPE_AST;
}
