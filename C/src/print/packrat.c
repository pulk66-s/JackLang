#include "print/packrat.h"
#include "print/repartition.h"
#include <stdio.h>

void print_packrat(struct result *r)
{
    if (!r->success || !r->size) {
        printf("packrat Failed to parse, success: %d, size: %ld\n", r->success, r->size);
        return;
    }
    repartition(r);
}
