#include "print/program.h"
#include "print/repartition.h"
#include "logger.h"

void print_program(struct result *program)
{
    struct program_cpt *prgm = program->data;

    logger().syntax("\"Program\": [\n");
    for (size_t i = 0; prgm->exprs[i] != NULL; i++) {
        struct result *expr = prgm->exprs[i];

        logger().syntax("{\n");
        repartition(expr);
        logger().syntax("},\n");
    }
    logger().syntax("],\n");
}
