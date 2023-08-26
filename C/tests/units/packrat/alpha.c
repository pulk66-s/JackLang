#include "units/packrat/alpha.h"
#include "units/packrat/init.h"
#include "units/tokens/create_tokens.h"
#include "parsing.h"
#include "units/asserts.h"
#include <stdio.h>

bool test_alpha_char(void)
{
    const char *file_path = "tests/files/words/alpha_char.cl";
    const char ***tokens = create_tokens(file_path);
    struct parser *p = init_packrat_parsing(tokens);
    struct result *res;
    char c;

    save(p);
    c = next(p);
    rollback(p);
    res = alpha(p);
    if (!assert_not_null(res)) {
        return false;
    }
    if (!assert_int_eq(res->datatype, CHAR)) {
        return false;
    }
    if (!assert_char_eq(*(char *)res->data, c)) {
        return false;
    }
    return true;
}

bool test_non_alpha_char(void)
{
    const char *file_path = "tests/files/words/non_alpha_char.cl";
    const char ***tokens = create_tokens(file_path);
    struct parser *p = init_packrat_parsing(tokens);

    return assert_null(alpha(p));
}
