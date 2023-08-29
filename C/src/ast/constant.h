#ifndef __CL_AST_CONSTANT_H__
#define __CL_AST_CONSTANT_H__

#include "parsing.h"
#include <stdint.h>

enum constant_type {
    INT32
};

struct constant_ast {
    enum constant_type type;
    union {
        int32_t int32;
    } u;
};

/**
 * @brief           Create a constant from the CPT.
 * @param   result  The current program CPT.
 * @return          The constant AST.
*/
struct constant_ast *create_constant(struct result *res);

#endif
