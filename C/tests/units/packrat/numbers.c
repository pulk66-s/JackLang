#include "units/packrat/init.h"
#include "units/packrat/numbers.h"
#include "units/asserts.h"
#include "parsing.h"
#include "units/tokens.h"

bool test_digit(void)
{
    const char *file_path = "tests/files/number/digit.cl";
    const char ***tokens = create_tokens(file_path);
    struct parser *p = init_packrat_parsing(tokens);
    struct result *res = number(p);

    if (!assert_not_null(res)) {
        return false;
    }
    if (!assert_int_eq(res->datatype, NUMBER)) {
        return false;
    }
    if (!assert_int_eq(*(int *)res->data, 3)) {
        return false;
    }
    return true;
}

bool test_number(void)
{
    const char *file_path = "tests/files/number/basic_number.cl";
    const char ***tokens = create_tokens(file_path);
    struct parser *p = init_packrat_parsing(tokens);
    struct result *res = number(p);

    if (!assert_not_null(res)) {
        return false;
    }
    if (!assert_int_eq(res->datatype, NUMBER)) {
        return false;
    }
    if (!assert_int_eq(*(int *)res->data, 42)) {
        return false;
    }
    return true;
}
