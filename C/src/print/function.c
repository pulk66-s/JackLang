#include "print/function.h"
#include "grammar/function.h"
#include <stdio.h>

void print_function(struct result *r)
{
    if (!r->success) {
        printf("Function declaration failed\n");
        return;
    }

    struct function *fn = r->data;

    printf("Function declaration: %s %s\n", fn->type, fn->name);
}