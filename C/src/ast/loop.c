#include "ast/loop.h"
#include "ast/expr.h"

struct loop_ast *create_loop_ast(struct result *r)
{
    struct loop_cpt *cpt = r->data;
    struct loop_ast *loop = malloc(sizeof(struct loop_ast));

    loop->condition = create_third_expr(cpt->cond);
    loop->increment = cpt->iter ? create_third_expr(cpt->iter) : NULL;
    loop->init = cpt->start ? create_third_expr(cpt->start) : NULL;
    loop->body = malloc(sizeof(struct secondary_expr_ast *) * (cpt->body->size + 1));
    loop->body[cpt->body->size] = NULL;
    for (size_t i = 0; i < cpt->body->size; i++)
        loop->body[i] = create_secondary_expr(&cpt->body->data[i]);
    return loop;
}
