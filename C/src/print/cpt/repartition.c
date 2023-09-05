#include "print/cpt/loop.h"
#include "print/cpt/repartition.h"
#include "print/cpt/program.h"
#include "print/cpt/expr.h"
#include "print/cpt/operation.h"
#include "print/cpt/numbers.h"
#include "print/cpt/string.h"
#include "print/cpt/char.h"
#include "print/cpt/function.h"
#include "print/cpt/ret.h"
#include "print/cpt/variables.h"
#include "print/cpt/keyword.h"
#include "print/cpt/condition.h"
#include "print/cpt/comparison.h"
#include <stdio.h>

void repartition(struct result *res)
{
    switch (res->datatype) {
        case PROGRAM:
            print_program(res);
            break;
        case EXPR:
            print_expr(res);
            break;
        case OPERATION:
            print_operation(res);
            break;
        case NUMBER:
            print_numbers(res);
            break;
        case VAR:
            print_string(res);
            break;
        case CHAR:
            print_char(res);
            break;
        case RET:
            print_ret(res);
            break;
        case FUNCTION_DECL:
            print_function(res);
            break;
        case VARIABLE_DECL:
            print_variable_decl(res);
            break;
        case CONDITION:
            print_if_stmt(res);
            break;
        case KEYWORD:
            print_keyword(res);
            break;
        case COMPARISON:
            print_comparison(res);
            break;
        case LOOP:
            print_loop_cpt(res);
            break;
        case VARIABLE_REDECL:
            print_variable_redecl(res);
            break;
        default:
            printf("Unknown datatype %d\n", res->datatype);
            break;
    }
}
