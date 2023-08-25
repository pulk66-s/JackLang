#ifndef __CL_GRAMMAR_WORD_H__
#define __CL_GRAMMAR_WORD_H__

#include "grammar/types.h"

struct result word(struct packrat *p);
struct result number(struct packrat *p);
struct result alpha_letter(struct packrat *p);
struct result alphanumeric(struct packrat *p);

#endif