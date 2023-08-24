#include "grammar/operation/basic.h"
#include "grammar/default.h"
#include "grammar/word.h"
#include <stdlib.h>
#include <stdio.h>

static struct result primary_operator(struct packrat *p)
{
    char c = next(p);
    char buffer[2] = {c, '\0'};

    switch (c) {
        case '*':
        case '/':
        case '%':
            return (struct result) {
                .success = true,
                .size = 1,
                .datatype = CHAR,
                .data = buffer
            };
        default:
            return FAIL_RESULT;
    }
}

static struct result secondary_operator(struct packrat *p)
{
    char c = next(p);
    char *buff = malloc(sizeof(char) * 2);

    buff[0] = c;
    buff[1] = '\0';
    switch (c) {
        case '+':
        case '-':
            return (struct result) {
                .success = true,
                .size = 1,
                .datatype = CHAR,
                .data = buff
            };
        default:
            return FAIL_RESULT;
    }
}

static struct result primary_operation(struct packrat *p)
{
    return FAIL_RESULT;
}

static struct result left_operand(struct packrat *p)
{
    return number(p);
}

static struct result right_operand(struct packrat *p)
{
    return number(p);
}

static struct result secondary_operation(struct packrat *p)
{
    struct result res = sequence(p, (expr_t[]) {
        left_operand,
        secondary_operator,
        right_operand
    }, 3);

    if (!res.success) return FAIL_RESULT;

    struct operation *op = malloc(sizeof(struct operation));
    struct result *datas = res.data;

    *op = (struct operation) {
        .left = &datas[0],
        .right = &datas[2],
        .operand = *(char *)datas[1].data
    };
    return (struct result) {
        .success = true,
        .size = 3,
        .datatype = OPERATION,
        .data = op
    };
}

struct result operation(struct packrat *p)
{
    return secondary_operation(p);
}
