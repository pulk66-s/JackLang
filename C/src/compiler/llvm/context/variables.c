#include "compiler/llvm/context/variables.h"
#include <stdlib.h>
#include <string.h>

static struct variable_context_llvm *context = NULL;

/**
 * @brief           Store a variable in the context.
 * @param   name    The name of the variable.
 * @param   value   The value of the variable.
 * @return          The variable context.
*/
void llvm_variable_context_store(char *name, LLVMValueRef value)
{
    struct variable_context_llvm *new_context = malloc(sizeof(struct variable_context_llvm));

    new_context->name = name;
    new_context->value = value;
    new_context->next = context;
    context = new_context;
}

/**
 * @brief           Get a variable from the context.
 * @param   name    The name of the variable.
 * @return          The variable context.
*/
LLVMValueRef llvm_variable_context_get(char *name)
{
    struct variable_context_llvm *current = context;

    while (current) {
        if (!strcmp(current->name, name)) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}
