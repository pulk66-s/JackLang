#include "print/function.h"
#include "print/repartition.h"
#include "grammar/function.h"
#include <stdio.h>

void print_function_decl(struct result *r)
{
    if (!r->success) {
        printf("Function declaration failed\n");
        return;
    }

    struct function *fn = r->data;

    printf("Function declaration: %s %s\n", fn->type, fn->name);
    if (!fn->args) {
        printf("No args\n");
        return;
    }
    if (!fn->args->success) {
        printf("Args declaration failed\n");
        return;
    }
    printf("body size %ld %d\n", fn->body->size, fn->body->datatype);
    repartition(fn->args);
    repartition(fn->body);
}

void print_arg_decl(struct result *r)
{
    if (!r->success) {
        printf("Argument declaration failed\n");
        return;
    }

    if (r->size == 1) {
        struct arg *arg = r->data;

        printf("Argument declaration: %s %s\n", arg->type, arg->name);
        return;
    }
    for (size_t i = 0; i < r->size; i++) {
        struct result *arg = &((struct result *) r->data)[i];

        repartition(arg);
    }
}
