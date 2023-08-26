#include "units/categories/launch.h"
#include "logger.h"
#include <stdlib.h>

/**
 * @brief           Create a default category
 * @param   name    The name of the category
 * @param   desc    The description of the category
 * @return          The category
*/
struct category *create_default_category(char *name, char *desc)
{
    struct category *category = malloc(sizeof(struct category));

    *category = (struct category) {
        .name = name,
        .description = desc,
        .tests = NULL,
        .next = NULL
    };
    return category;
}

/**
 * @brief               Launches the unit tests for the categories
 * @param   categories  The categories to test
*/
void launch_categories_unit_tests(struct categories *categories)
{
    struct category *category = categories->categories;

    while (category != NULL) {
        launch_category_unit_tests(category);
        category = category->next;
    }
}

/**
 * @brief               Launch all the tests from a category
 * @param   category    The category to launch the tests from
*/
void launch_category_unit_tests(struct category *category)
{
    struct tests *tests = category->tests;
    size_t success = 0, failure = 0;

    while (tests != NULL) {
        if (tests->test()) {
            logger().success("Test %s passed\n", tests->name);
            success++;
        } else {
            logger().failure("Test %s failed\n", tests->name);
            failure++;
        }
        tests = tests->next;
    }
    logger().success("Category %s: %zu/%zu tests passed\n", category->name,
        success, success + failure);
}
