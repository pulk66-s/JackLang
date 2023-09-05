#include "ast/condition.h"
#include "ast/expr.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct condition_ast *create_condition(struct result *cpt)
{
    struct condition_cpt *condition_cpt = cpt->data;
    struct condition_ast *condition_ast = malloc(sizeof(struct condition_ast));
    struct result *datas;

    memset(condition_ast, 0, sizeof(struct condition_ast));
    condition_ast->cond = create_third_expr(condition_cpt->cond);
    condition_ast->then = malloc(sizeof(struct secondary_expr_ast *) * (condition_cpt->body->size + 1));
    condition_ast->then[condition_cpt->body->size] = NULL;
    datas = (struct result *)condition_cpt->body->data;
    for (size_t i = 0; i < condition_cpt->body->size; i++) {
        condition_ast->then[i] = create_secondary_expr(&datas[i]);
    }
    if (condition_cpt->else_stmt) {
        condition_ast->else_ = malloc(sizeof(struct secondary_expr_ast *) * (condition_cpt->else_stmt->size + 1));
        condition_ast->else_[condition_cpt->else_stmt->size] = NULL;
        if (condition_cpt->else_stmt->datatype == CONDITION) {
            condition_ast->else_[0] = create_secondary_expr(condition_cpt->else_stmt);
            return condition_ast;
        } else {
            datas = (struct result *)condition_cpt->else_stmt->data;
            for (size_t i = 0; i < condition_cpt->else_stmt->size; i++) {
                condition_ast->else_[i] = create_secondary_expr(&datas[i]);
            }
        }
    } else {
        condition_ast->else_ = NULL;
    }
    return condition_ast;
}
