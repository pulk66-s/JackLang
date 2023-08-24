#include "print/repartition.h"
#include "print/program.h"
#include "print/word.h"
#include "print/expr.h"
#include "print/operation.h"
#include <stdio.h>

static void print_datatype(enum result_data_type type)
{
    switch (type) {
        case EXPR_STATEMENT:
            printf("EXPR_STATEMENT");
            break;
        case STRING:
            printf("STRING");
            break;
        case CHAR:
            printf("CHAR");
            break;
        case UNKNOWN:
            printf("UNKNOWN");
            break;
        case OPERATION:
            printf("OPERATION");
            break;
        case NUMBER:
            printf("NUMBER");
            break;
        case PROGRAM:
            printf("PROGRAM");
            break;
        default:
            printf("Unknown datatype: %d\n", type);
            break;
    };
}

void repartition(struct result *r)
{
    switch (r->datatype) {
        case EXPR_STATEMENT:
            print_expr(r);
            break;
        case STRING:
            print_string(r);
            break;
        case CHAR:
            print_char(r);
            break;
        case NUMBER:
            print_nb(r);
            break;
        case PROGRAM:
            print_program(r);
            break;
        case OPERATION:
            print_operation(r);
            break;
        default:
            printf("Unknown datatype: ");
            print_datatype(r->datatype);
            break;
    }
}
