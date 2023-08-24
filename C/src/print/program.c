#include "grammar/program.h"
#include "print/repartition.h"
#include <stdio.h>

void print_program(struct result *r)
{
    if (!r->success) {
        printf("Program Failed to parse\n");
        return;
    }

    struct result *datas = r->data;

    for (size_t i = 0; i < r->size; i++) {
        printf("Program %ld: ", i);
        repartition(&datas[i]);
    }
}
