#include "print/operation.h"
#include "print/repartition.h"
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

    repartition(left);
    printf(" %c ", operand);
    repartition(right);
}