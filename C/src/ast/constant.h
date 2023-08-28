#ifndef __CL_AST_CONSTANT_H__
#define __CL_AST_CONSTANT_H__

#include "parsing.h"
#include <stdint.h>

union constant_ast {
    int32_t int32;
};

/**
 * @brief           Create a constant from the CPT.
 * @param   result  The current program CPT.
 * @return          The constant AST.
*/
union constant_ast *create_constant(struct result *res);

#endif
