#include "print/cpt/repartition.h"
#include "print/cpt/program.h"
#include "print/cpt/expr.h"
#include "print/cpt/operation.h"
#include "print/cpt/numbers.h"
#include "print/cpt/string.h"
#include "print/cpt/char.h"
#include "print/cpt/ret.h"
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
        case STRING:
            print_string(res);
            break;
        case CHAR:
            print_char(res);
            break;
        case RET:
            print_ret(res);
            break;
        default:
            printf("Unknown datatype %d\n", res->datatype);
            break;
    }
}
