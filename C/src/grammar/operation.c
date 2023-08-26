#include "grammar/operation.h"
#include "parsing/words.h"
#include "parsing/default/char.h"

static bool is_operand(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

struct result *operation(struct parser *p)
{
    struct result *left_res, *right_res, *operand_res;
    struct operation_cpt *op;
    char operand;

    save(p);
    left_res = number(p);
    if (!left_res) {
        rollback(p);
        return NULL;
    }
    operand_res = character(p);
    if (!operand_res) {
        rollback(p);
        return NULL;
    }
    operand = *(char *)operand_res->data;
    if (!is_operand(operand)) {
        rollback(p);
        return NULL;
    }
    right_res = number(p);
    if (!right_res) {
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
    return result(op, OPERATION, 1);
}
