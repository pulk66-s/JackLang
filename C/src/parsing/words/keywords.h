#ifndef __CL_PARSING_WORDS_KEYWORDS_H__
#define __CL_PARSING_WORDS_KEYWORDS_H__

#include "parsing/default.h"

struct result *plus_equal(struct parser *p);
struct result *minus_equal(struct parser *p);
struct result *star_equal(struct parser *p);
struct result *slash_equal(struct parser *p);
struct result *percent_equal(struct parser *p);

#endif