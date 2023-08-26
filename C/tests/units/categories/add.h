#ifndef __CL_TESTS_CATEGORIES_ADD_H__
#define __CL_TESTS_CATEGORIES_ADD_H__

#include "units/categories/types.h"

/**
 * @brief               Add a category to the categories list
 * @param categories    The categories list
 * @param category      The category to add
*/
void add_category(struct categories *categories, struct category *category);

/**
 * @brief           Add a test to a category
 * @param category  The category
 * @param test      The test to add
*/
void add_test(struct category *category, struct tests *test);

/**
 * @brief       Add a unit test from a function
 * @param test  The tests list
*/
struct tests *create_unit_test(test_t function, char *name);

#endif