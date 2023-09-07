#include "print/cpt/program.h"
#include "print/cpt/repartition.h"
#include "logger.h"

void print_program(struct result *program)
{
    struct program_cpt *prgm = program->data;
    struct result *datas = (struct result *)prgm->exprs->data;

    logger().cpt("{\"Program\": [\n");
    for (size_t i = 0; i < prgm->exprs->size; i++) {
        logger().cpt("{\n");
        repartition(&datas[i]);
        logger().cpt("},\n");
    }
    logger().cpt("]},\n");
}
