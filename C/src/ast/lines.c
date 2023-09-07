#include "ast/lines.h"
#include <stdlib.h>

static struct line_ast *create_line(struct result *expr)
{
    struct line_ast *line = malloc(sizeof(struct line_ast));

    *line = (struct line_ast) {
        .expr = create_primary_expr(expr)
    };
    return line;
}

struct line_ast **create_lines_ast(struct program_cpt *cpt)
{
    struct line_ast **lines = malloc(sizeof(struct line_ast *) * (cpt->exprs->size + 1));
    struct result *datas = (struct result *)cpt->exprs->data;

    lines[cpt->exprs->size] = NULL;
    for (size_t i = 0; i < cpt->exprs->size; i++) {
        printf("LINE %ld\n", i);
        lines[i] = create_line(&datas[i]);
    }
    return lines;
}
