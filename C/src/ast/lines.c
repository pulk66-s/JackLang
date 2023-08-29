#include "ast/lines.h"
#include <stdlib.h>

static size_t count_exprs(struct result **exprs)
{
    size_t nb_exprs = 0;

    for (size_t i = 0; exprs[i]; i++)
        nb_exprs++;
    return nb_exprs;
}

static struct line_ast *create_line(struct result *expr)
{
    struct line_ast *line = malloc(sizeof(struct line_ast));

    *line = (struct line_ast) {
        .expr = create_primary_expr(expr->data)
    };
    return line;
}

struct line_ast **create_lines_ast(struct program_cpt *cpt)
{
    size_t nb_exprs = count_exprs(cpt->exprs);
    struct line_ast **lines = malloc(sizeof(struct line_ast *) * (nb_exprs + 1));

    lines[nb_exprs] = NULL;
    for (size_t i = 0; i < nb_exprs; i++) {
        lines[i] = create_line(cpt->exprs[i]);
    }
    return lines;
}
