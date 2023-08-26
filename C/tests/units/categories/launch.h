#ifndef __CL_TESTS_UNITS_CATEGORIES_LAUNCH_H__
#define __CL_TESTS_UNITS_CATEGORIES_LAUNCH_H__

#include "units/categories.h"

/**
 * @brief               Launches the unit tests for the categories
 * @param   categories  The categories to test
*/
void launch_categories_unit_tests(struct categories *categories);

/**
 * @brief               Launch all the tests from a category
 * @param   category    The category to launch the tests from
*/
void launch_category_unit_tests(struct category *category);

#endif