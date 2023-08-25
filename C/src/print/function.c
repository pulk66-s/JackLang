#include "print/function.h"
#include "print/repartition.h"
#include "grammar/function.h"
#include "logger.h"
#include <stdio.h>

void print_function_decl(struct result *r)
{
    if (!r->success) {
        return;
    }

    struct function *fn = r->data;

    if (!fn->args) {
        return;
    }
    if (!fn->args->success) {
        return;
    }
    logger().syntax("\"Function\": {\n");
    repartition(fn->args);
    repartition(fn->body);
    logger().syntax("},\n");
}

void print_arg_decl(struct result *r)
{
    if (!r->success) {
        return;
    }

    if (r->size == 1) {
        struct arg *arg = r->data;

        logger().syntax("\"Argument\": {\"type\": \"%s\", \"name\": \"%s\"},\n", arg->type, arg->name);
        return;
    }
    for (size_t i = 0; i < r->size; i++) {
        struct result *arg = &((struct result *) r->data)[i];

        repartition(arg);
    }
}
