#include "ast/context/variables.h"
#include <stdlib.h>
#include <string.h>

static struct context_var *context_vars = NULL;

void new_context_var(char *name)
{
    struct context_var *new_var = malloc(sizeof(struct context_var));

    new_var->name = name;
    new_var->next = context_vars;
    context_vars = new_var;
}

bool exists_context_var(char *name)
{
    struct context_var *var = context_vars;

    while (var != NULL) {
        if (strcmp(var->name, name) == 0) {
            return true;
        }
        var = var->next;
    }

    return false;
}
