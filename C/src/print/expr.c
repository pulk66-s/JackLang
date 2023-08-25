#include "print/expr.h"
#include "print/repartition.h"
#include "grammar/expr.h"
#include <stdio.h>

void print_expr(struct result *r)
{
    printf("Enter print_expr\n");
    if (!r->success) {
        printf("Expr Failed to parse\n");
        return;
    }

    if (r->size == 1) {
        struct expr *e = r->data;

        repartition(e->data);
    } else {
        struct result *datas = r->data;

        for (size_t i = 0; i < r->size; i++) {
            struct result *data = &datas[i];

            repartition(data);
        }
    }
}
