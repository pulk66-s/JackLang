#include "units/packrat/next.h"
#include "units/packrat/init.h"
#include "units/tokens.h"
#include "parsing.h"
#include "files.h"
#include "units/asserts.h"
#include "units/tokens/create_tokens.h"
#include "parsing.h"
#include <stdio.h>
#include <stdbool.h>

bool basic_next_test(void)
{
    const char *file_path = "tests/files/words/many_alpha.cl";
    const char *content = read_file(file_path);
    const char ***tokens = create_tokens(file_path);
    struct parser *p = init_packrat_parsing(tokens);

    for (size_t i = 0; content[i]; i++) {
        if (content[i] == ' ' || content[i] == '\n') {
            continue;
        }
        if (!assert_char_eq(content[i], next(p))) {
            return false;
        }
    }
    return true;
}

bool too_far_next(void)
{
    const char *file_path = "tests/files/words/many_alpha.cl";
    const char *content = read_file(file_path);
    const char ***tokens = create_tokens(file_path);
    struct parser *p = init_packrat_parsing(tokens);

    for (size_t i = 0; content[i]; i++) {
        if (content[i] == ' ' || content[i] == '\n') {
            continue;
        }
        next(p);
    }
    for (size_t i = 0; i < 100; i++) {
        if (!assert_char_eq(0, next(p))) {
            return false;
        }
    }
    return true;
}