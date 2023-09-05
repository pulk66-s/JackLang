#include "print/ast/comparison.h"
#include "print/ast/expr.h"
#include "logger.h"

static void print_comparison_operand(enum comparison_operand_ast op)
{
    switch (op) {
        case COMPARISON_OPERAND_EQUAL:
            logger().ast("\"operand\": \"==\",\n");
            break;
        case COMPARISON_OPERAND_NOT_EQUAL:
            logger().ast("\"operand\": \"!=\",\n");
            break;
        case COMPARISON_OPERAND_GREATER:
            logger().ast("\"operand\": \">\",\n");
            break;
        case COMPARISON_OPERAND_LESS:
            logger().ast("\"operand\": \"<\",\n");
            break;
        case COMPARISON_OPERAND_GREATER_EQUAL:
            logger().ast("\"operand\": \">=\",\n");
            break;
        case COMPARISON_OPERAND_LESS_EQUAL:
            logger().ast("\"operand\": \"<=\",\n");
            break;
        default:
            logger().ast("\"operand\": \"UNKNOWN\",\n");
            break;
    }
}

void print_comparison_ast(struct comparison_ast *comparison)
{
    logger().ast("\"comparison\": {\n");
    print_comparison_operand(comparison->operand);
    logger().ast("\"left\": {\n");
    print_third_expr_ast(comparison->left);
    logger().ast("},\n");
    logger().ast("\"right\": {\n");
    print_third_expr_ast(comparison->right);
    logger().ast("},\n");
    logger().ast("},\n");
}