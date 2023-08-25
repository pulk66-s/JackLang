#include "print/expr.h"
#include "print/repartition.h"
#include "grammar/expr.h"
#include <stdio.h>

void print_expr(struct result *r)
{
    if (!r->success) {
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
