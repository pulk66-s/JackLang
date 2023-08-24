#include "print/repartition.h"
#include "print/word.h"
#include "print/expr.h"
#include <stdio.h>

static void print_datatype(enum result_data_type type)
{
    switch (type) {
        case EXPR:
            printf("EXPR");
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
        default:
            printf("Unknown datatype: %d\n", type);
            break;
    };
}

void repartition(struct result *r)
{
    switch (r->datatype) {
        case EXPR:
            print_expr(r);
            break;
        case STRING:
            print_string(r);
            break;
        case CHAR:
            print_char(r);
            break;
        default:
            printf("Unknown datatype: ");
            print_datatype(r->datatype);
            break;
    }
}