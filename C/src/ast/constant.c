#include "ast/constant.h"

/**
 * @brief           Create a constant from the CPT.
 * @param   result  The current program CPT.
 * @return          The constant AST.
*/
struct constant_ast *create_constant(struct result *res)
{
    struct constant_ast *constant = malloc(sizeof(struct constant_ast));

    switch (res->datatype) {
        case NUMBER:
            constant->type = INT32;
            constant->u.int32 = *(int32_t *)res->data;
            break;
        default:
            constant = NULL;
            break;
    }
    return constant;
}
