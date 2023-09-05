#include "print/cpt/repartition.h"
#include "print/cpt/operation.h"
#include "logger.h"
#include "grammar.h"

void print_operation(struct result *res)
{
    struct operation_cpt *cpt = res->data;

    if (res->datatype != OPERATION) {
        logger().cpt_debug("print_operation: res->datatype != OPERATION");
        return;
    }
    logger().cpt("\"Operation\": {\n");
    logger().cpt("\"Operand\": \"%c\",\n", cpt->operand);
    logger().cpt("\"Left\": {\n");
    repartition(cpt->left);
    logger().cpt("},\n");
    logger().cpt("\"Right\": {\n");
    repartition(cpt->right);
    logger().cpt("}\n");
    logger().cpt("},\n");
}
