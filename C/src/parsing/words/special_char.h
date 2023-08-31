#ifndef __CL_PARSING_WORDS_SPECIAL_CHAR_H__
#define __CL_PARSING_WORDS_SPECIAL_CHAR_H__

#include "parsing/manager.h"

struct result *semicolon(struct parser *p);
struct result *open_par(struct parser *p);
struct result *close_par(struct parser *p);
struct result *open_curly(struct parser *p);
struct result *close_curly(struct parser *p);
struct result *comma(struct parser *p);
struct result *equal(struct parser *p);

#endif