#include "print/packrat.h"
#include "print/repartition.h"
#include <stdio.h>

void print_packrat(struct result *r)
{
    if (!r->success) {
        printf("Failed to parse\n");
        return;
    }
    if (r->size == 1) {
        repartition(r);
        return;
    }
    for (size_t i = 0; i < r->size; i++) {
        struct result *res = (struct result *)r->data + i;

        repartition(res);
    }
}
