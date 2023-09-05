#include "ast/comparison.h"
#include "ast/expr.h"
#include <string.h>

static enum comparison_operand_ast create_comparison_operand(char *comp)
{
    if (strcmp(comp, "==") == 0)
        return COMPARISON_OPERAND_EQUAL;
    if (strcmp(comp, "!=") == 0)
        return COMPARISON_OPERAND_NOT_EQUAL;
    if (strcmp(comp, ">") == 0)
        return COMPARISON_OPERAND_GREATER;
    if (strcmp(comp, "<") == 0)
        return COMPARISON_OPERAND_LESS;
    if (strcmp(comp, ">=") == 0)
        return COMPARISON_OPERAND_GREATER_EQUAL;
    if (strcmp(comp, "<=") == 0)
        return COMPARISON_OPERAND_LESS_EQUAL;
    return COMPARISON_OPERAND_NONE;
}

struct comparison_ast *create_comparison(struct result *cpt)
{
    struct comparison_cpt *comparison_cpt = cpt->data;
    struct comparison_ast *comparison_ast = malloc(sizeof(struct comparison_ast));

    memset(comparison_ast, 0, sizeof(struct comparison_ast));
    comparison_ast->operand = create_comparison_operand(comparison_cpt->comp);
    comparison_ast->left = create_third_expr(comparison_cpt->left);
    comparison_ast->right = create_third_expr(comparison_cpt->right);
    return comparison_ast;
}
