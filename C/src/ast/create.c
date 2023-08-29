#include "ast/create.h"
#include "ast/lines.h"

struct program_ast *create_program_ast(struct program_cpt *cpt)
{
    struct program_ast *ast = malloc(sizeof(struct program_ast));

    *ast = (struct program_ast) {
        .lines = create_lines_ast(cpt)
    };
    return ast;
}
