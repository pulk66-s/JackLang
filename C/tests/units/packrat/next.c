#include "units/packrat/next.h"
#include "units/tokens.h"
#include "parsing.h"
#include "files.h"
#include "units/asserts.h"
#include <stdio.h>
#include <stdbool.h>

bool basic_next_test(void)
{
    const char *file_path = "tests/files/words/many_alpha.cl";
    const char *content = read_file(file_path);
    const char ***tokens = create_tokens(file_path);
    struct parsing *p = init_packrat_parsing(tokens);

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