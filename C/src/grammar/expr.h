#ifndef __CL_GRAMMAR_EXPR_H__
#define __CL_GRAMMAR_EXPR_H__

#include "parsing/manager.h"

struct result *expr(struct parser *p);
struct result *primary_expression(struct parser *p);
struct result *secondary_expression(struct parser *p);
struct result *third_expression(struct parser *p);
struct result *expr_value(struct parser *p);

#endif
