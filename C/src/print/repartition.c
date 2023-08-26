#include "print/repartition.h"
#include "print/program.h"
#include "print/expr.h"
#include "print/operation.h"
#include "print/numbers.h"
#include "print/string.h"
#include "print/char.h"
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
        default:
            printf("Unknown datatype %d\n", res->datatype);
            break;
    }
}
