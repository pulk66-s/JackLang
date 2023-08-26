#include "print/repartition.h"
#include "print/operation.h"
#include "logger.h"
#include "grammar.h"

void print_operation(struct result *res)
{
    struct operation_cpt *cpt = res->data;

    if (res->datatype != OPERATION) {
        logger().syntax_debug("print_operation: res->datatype != OPERATION");
        return;
    }
    logger().syntax("\"Operation\": {\n");
    logger().syntax("\"Operand\": \"%c\",\n", cpt->operand);
    logger().syntax("\"Left\": {\n");
    repartition(cpt->left);
    logger().syntax("},\n");
    logger().syntax("\"Right\": {\n");
    repartition(cpt->right);
    logger().syntax("}\n");
}
