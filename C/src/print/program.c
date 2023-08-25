#include "grammar/program.h"
#include "print/repartition.h"
#include "logger.h"
#include <stdio.h>

void print_program(struct result *r)
{
    if (!r->success) {
        return;
    }

    struct result *datas = r->data;

    logger().syntax("\"Program\": [\n");
    for (size_t i = 0; i < r->size; i++) {
        repartition(&datas[i]);
    }
    logger().syntax("],\n");
}
