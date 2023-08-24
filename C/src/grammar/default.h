#ifndef __CL_GRAMMAR_DEFAULT_H__
#define __CL_GRAMMAR_DEFAULT_H__

#include "grammar/types.h"

char next(struct packrat *p);
void next_word(struct packrat *p);
struct result zero_or_more(struct packrat *p, expr_t e);

#endif