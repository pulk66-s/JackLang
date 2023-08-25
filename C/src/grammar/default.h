#ifndef __CL_GRAMMAR_DEFAULT_H__
#define __CL_GRAMMAR_DEFAULT_H__

#include "grammar/types.h"

struct result zero_or_more(struct packrat *p, expr_t e);
struct result zero_or_one(struct packrat *p, expr_t e);
struct result sequence(struct packrat *p, expr_t *exprs, size_t size);
struct result ordered_choice(struct packrat *p, expr_t *exprs, size_t size);

#endif
