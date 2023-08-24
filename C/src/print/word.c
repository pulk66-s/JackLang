#include "print/word.h"
#include <stdio.h>

void print_string(struct result *r)
{
    if (!r->success) {
        printf("Failed to parse\n");
        return;
    }

    char *s = r->data;

    printf("String: %s\n", s);
}

void print_char(struct result *r)
{
    if (!r->success) {
        printf("Failed to parse\n");
        return;
    }

    char *c = r->data;

    printf("Char: %c\n", *c);
}