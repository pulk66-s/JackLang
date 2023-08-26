#include "units/packrat/init.h"
#include "units/categories.h"
#include "units/packrat/tests.h"
#include "parsing.h"
#include <stdlib.h>

/**
 * @brief   Initializes the packrat unit tests.
 * @return  The packrat category.
*/
struct category *init_packrat_category(void)
{
    struct category *category = malloc(sizeof(struct category));

    category->name = "Packrat";
    category->description = "Tests the packrat parser";
    category->tests = NULL;
    category->next = NULL;

    add_test(category, create_unit_test(basic_next_test, "basic_next_test"));
    return category;
}

/**
 * @brief   Initialize the parsing unit tests
 * @return  The parsing struct
*/
struct parsing *init_packrat_parsing(const char ***tokens)
{
    struct parsing *parsing = malloc(sizeof(struct parsing));

    *parsing = (struct parsing) {
        .pos = (struct pos) {
            .x = 0,
            .y = 0,
            .cursor = 0
        },
        .tokens = tokens
    };
    return parsing;
}
