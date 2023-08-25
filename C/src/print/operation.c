#include "print/operation.h"
#include "print/repartition.h"
#include "logger.h"
#include <stdio.h>

void print_operation(struct result *r)
{
    if (!r->success) {
        printf("Operation failed\n");
        return;
    }

    struct operation *op = r->data;
    struct result *left = op->left;
    struct result *right = op->right;
    char operand = op->operand;

    logger().syntax("\"Operation\": {\n");
    repartition(left);
    logger().syntax("\"Operand\": \"%c\",\n", operand);
    repartition(right);
    logger().syntax("},\n");
}
