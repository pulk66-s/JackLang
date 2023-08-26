#include "units/categories/add.h"
#include <stdlib.h>

/**
 * @brief               Add a category to the categories list
 * @param categories    The categories list
 * @param category      The category to add
*/
void add_category(struct categories *categories, struct category *category)
{
    if (!categories) {
        return;
    }
    category->next = categories->categories;
    categories->categories = category;
}

/**
 * @brief           Add a test to a category
 * @param category  The category
 * @param test      The test to add
*/
void add_test(struct category *category, struct tests *test)
{
    if (!category) {
        return;
    }
    test->next = category->tests;
    category->tests = test;
}

/**
 * @brief       Add a unit test from a function
 * @param test  The tests list
*/
struct tests *create_unit_test(test_t function, char *name)
{
    struct tests *test = malloc(sizeof(struct tests));

    *test = (struct tests) {
        .next = NULL,
        .test = function,
        .name = name
    };
    return test;
}
