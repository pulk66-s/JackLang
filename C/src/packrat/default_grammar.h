#ifndef __JL_PACKRAT_DEFAULT_GRAMMAR_H__
#define __JL_PACKRAT_DEFAULT_GRAMMAR_H__

#include <stdbool.h>
#include <stdlib.h>

struct packrat {
    const char *content;
    size_t cursor;
};

struct packrat_result {
    bool success;
    const char *value;
};

typedef struct packrat_result (*parse_expr_t)(struct packrat *);

char next(struct packrat *p);
struct packrat_result and(struct packrat *p, parse_expr_t left, parse_expr_t right);
struct packrat_result or(struct packrat *p, parse_expr_t left, parse_expr_t right);
struct packrat_result not(struct packrat *p, parse_expr_t expr);
struct packrat_result one_or_more(struct packrat *p, parse_expr_t expr);

#endif
