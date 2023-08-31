#include "grammar/operation.h"
#include "grammar/expr.h"
#include "parsing.h"
#include "logger.h"

static bool is_operand(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

struct result *operation(struct parser *p)
{
    logger().cpt_debug("operation\n");

    struct result *left_res, *right_res, *operand_res;
    struct operation_cpt *op;
    char operand;

    save(p);
    left_res = expr_value(p);
    if (!left_res) {
        logger().cpt_debug("Error: left operand expected 1\n");
        rollback(p);
        return NULL;
    }
    operand_res = character(p);
    if (!operand_res) {
        logger().cpt_debug("Error: left operand expected 2\n");
        rollback(p);
        return NULL;
    }
    operand = *(char *)operand_res->data;
    if (!is_operand(operand)) {
        logger().cpt_debug("Error: left operand expected 3\n");
        rollback(p);
        return NULL;
    }
    right_res = ordered_choice(p, (parser_func[]){third_expression, expr_value}, 2);
    if (!right_res) {
        logger().cpt_debug("Error: left operand expected 4\n");
        rollback(p);
        return NULL;
    }
    op = malloc(sizeof(struct operation_cpt));
    *op = (struct operation_cpt) {
        .operand = operand,
        .left = left_res,
        .right = right_res
    };
    delete_save(p);
    logger().cpt_debug("operation: %c\n", operand);
    return result(op, OPERATION, 1);
}
