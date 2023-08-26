#include "units/packrat/operation.h"
#include "units/tokens.h"
#include "units/packrat.h"
#include "units/asserts.h"
#include "parsing.h"

bool test_basic_operation(void)
{
    const char *file_path = "tests/files/operation/basic.cl";
    const char ***tokens = create_tokens(file_path);
    struct parser *p = init_packrat_parsing(tokens);
    struct result *res = operation(p);

    if (!assert_not_null(res)) {
        return false;
    }
    if (!assert_int_eq(res->datatype, OPERATION)) {
        return false;
    }

    struct operation_cpt *op = res->data;
    struct result *left = op->left, *right = op->right;

    if (!assert_int_eq(left->datatype, NUMBER)) {
        return false;
    }
    if (!assert_int_eq(*(int *)left->data, 1)) {
        return false;
    }
    if (!assert_int_eq(right->datatype, NUMBER)) {
        return false;
    }
    if (!assert_int_eq(*(int *)right->data, 3)) {
        return false;
    }
    return true;
}
