#include "ast/constant.h"

/**
 * @brief           Create a constant from the CPT.
 * @param   result  The current program CPT.
 * @return          The constant AST.
*/
union constant_ast *create_constant(struct result *res)
{
    union constant_ast *constant = malloc(sizeof(union constant_ast));

    switch (res->datatype) {
        case NUMBER:
            constant->int32 = *(int32_t *)res->data;
            break;
        default:
            constant = NULL;
            break;
    }
    return constant;
}
