#ifndef __CL_GRAMMAR_LETTERS_H__
#define __CL_GRAMMAR_LETTERS_H__

#include "grammar/types.h"

struct result open_par(struct packrat *p);
struct result close_par(struct packrat *p);
struct result comma(struct packrat *p);
struct result open_curly(struct packrat *p);
struct result close_curly(struct packrat *p);

#endif