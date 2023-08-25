#include "print/word.h"
#include "logger.h"
#include <stdio.h>

void print_string(struct result *r)
{
    if (!r->success) {
        printf("string Failed to parse\n");
        return;
    }

    char *s = r->data;

    logger().syntax("\"String\": \"%s\",\n", s);
}

void print_char(struct result *r)
{
    if (!r->success) {
        printf("char Failed to parse\n");
        return;
    }

    char *c = r->data;

    logger().syntax("\"Char\": \"%c\",\n", *c);
}

void print_nb(struct result *r)
{
    if (!r->success) {
        printf("number Failed to parse\n");
        return;
    }

    int *nb = r->data;

    logger().syntax("\"Number\": %d,\n", *nb);
}