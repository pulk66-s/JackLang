#include "units/packrat/init.h"
#include "units/categories.h"
#include "units/packrat/tests.h"
#include "parsing.h"
#include <stdlib.h>

/**
 * @brief   Initialize the category that tests the numbers parser
 * @return  The category
*/
struct category *init_numbers_category(void)
{
    struct category *category = create_default_category("Numbers", "Tests the numbers parser");

    add_test(category, create_unit_test(test_digit, "test_digit"));
    add_test(category, create_unit_test(test_number, "test_number"));
    return category;
}

/**
 * @brief   Initializes the packrat unit tests.
 * @return  The packrat category.
*/
struct category *init_default_category(void)
{
    struct category *category = create_default_category("Packrat", "Tests the packrat parser");

    add_test(category, create_unit_test(basic_next_test, "basic_next_test"));
    add_test(category, create_unit_test(too_far_next, "too_far_next"));
    return category;
}

/**
 * @brief   Initialize the category that tests the words parser
 * @return  The category
*/
struct category *init_words_category(void)
{
    struct category *category = create_default_category("Words", "Tests the words parser");

    add_test(category, create_unit_test(test_alpha_char, "test_alpha_char"));
    add_test(category, create_unit_test(test_non_alpha_char, "test_non_alpha_char"));
    return category;
}

/**
 * @brief   Initialize the parsing unit tests
 * @return  The parsing struct
*/
struct parser *init_packrat_parsing(const char ***tokens)
{
    struct parser *parsing = malloc(sizeof(struct parser));

    *parsing = (struct parser) {
        .pos = (struct pos) {
            .x = 0,
            .y = 0,
            .cursor = 0
        },
        .tokens = tokens
    };
    return parsing;
}
