#include "print/expr.h"
#include "print/repartition.h"
#include "grammar/expr.h"
#include <stdio.h>

void print_expr(struct result *r)
{
    if (!r->success) {
        printf("Expr Failed to parse\n");
        return;
    }

    struct expr *e = r->data;
    struct result *datas = e->data;

    printf("Expr: %ld\n", r->size);
    for (size_t i = 0; i < r->size; i++) {
        printf("Expr %ld: ", i);
        repartition(&datas[i]);
    }
}
