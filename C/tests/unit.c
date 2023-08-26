#include "unit.h"
#include "units/categories.h"
#include "units/packrat.h"
#include <stdlib.h>

/**
 * @brief   Initializes all the unit tests.
 * @return  The categories list.
*/
static struct categories *init_tests(void)
{
    struct categories *categories = malloc(sizeof(struct categories));

    *categories = (struct categories) {
        .categories = NULL
    };
    add_category(categories, init_default_category());
    add_category(categories, init_words_category());
    add_category(categories, init_numbers_category());
    return categories;
}

/**
 * @brief Launches the unit tests.
*/
void launch_unit(void)
{
    struct categories *categories = init_tests();

    launch_categories_unit_tests(categories);
}
