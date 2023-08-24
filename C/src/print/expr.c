#include "print/expr.h"
#include "grammar/expr.h"
#include <stdio.h>

void print_expr(struct result *r)
{
    if (!r->success) {
        printf("Failed to parse\n");
        return;
    }

    struct expr *e = r->data;

    printf("Expr: %s, terminate: %c\n", e->name, e->terminate);
}
