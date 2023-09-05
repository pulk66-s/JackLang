#include "print/cpt/program.h"
#include "print/cpt/repartition.h"
#include "logger.h"

void print_program(struct result *program)
{
    struct program_cpt *prgm = program->data;

    logger().cpt("{\"Program\": [\n");
    for (size_t i = 0; prgm->exprs[i] != NULL; i++) {
        struct result *expr = prgm->exprs[i];

        logger().cpt("{\n");
        repartition(expr);
        logger().cpt("},\n");
    }
    logger().cpt("]},\n");
}
