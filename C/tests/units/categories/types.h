#ifndef __TESTS_CATEGORIES_TYPES_H__
#define __TESTS_CATEGORIES_TYPES_H__

#include <stdbool.h>

typedef bool (*test_t)(void);

struct tests {
    test_t test;
    char *name;
    struct tests *next;
};

struct category {
    char *name;
    char *description;
    struct tests *tests;
    struct category *next;
};

struct categories {
    struct category *categories;
};

#endif
