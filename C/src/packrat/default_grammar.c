#include "default_grammar.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char next(struct packrat *p)
{
    return p->content[p->cursor++];
}

struct packrat_result and(struct packrat *p, parse_expr_t left, parse_expr_t right)
{
    size_t save = p->cursor;
    bool result = left(p).success && right(p).success;

    if (!result)
        p->cursor = save;
    return (struct packrat_result) {
        .success = result,
        .value = NULL
    };
}

struct packrat_result or(struct packrat *p, parse_expr_t left, parse_expr_t right)
{
    size_t save = p->cursor;
    bool result = left(p).success || right(p).success;

    if (!result)
        p->cursor = save;
    return (struct packrat_result) {
        .success = result,
        .value = NULL
    };
}

struct packrat_result not(struct packrat *p, parse_expr_t expr)
{
    size_t save = p->cursor;
    bool result = !expr(p).success;

    if (!result)
        p->cursor = save;
    return (struct packrat_result) {
        .success = result,
        .value = NULL
    };
}

struct packrat_result one_or_more(struct packrat *p, parse_expr_t expr)
{
    char *buf = NULL;
    size_t size = 0;
    struct packrat_result res;

    while (true) {
        res = expr(p);
        if (!res.success) {
            break;
        }
        size += strlen(res.value);
        if (buf) {
            buf = realloc(buf, size + 1);
        } else {
            buf = malloc(size + 1);
            memset(buf, 0, size + 1);
        }
        strcat(buf, res.value);
    }
    buf[size] = '\0';
    return (struct packrat_result) {
        .success = size > 0,
        .value = buf
    };
}