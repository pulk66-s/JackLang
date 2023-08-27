#ifndef __CL_AST_LINES_H__
#define __CL_AST_LINES_H__

#include "grammar.h"
#include "ast/expr.h"

struct line_ast {
    union primary_expr_ast *expr;
};

struct line_ast **create_lines_ast(struct program_cpt *cpt);

#endif