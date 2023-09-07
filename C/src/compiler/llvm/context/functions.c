#include "compiler/llvm/context/functions.h"
#include "logger.h"
#include <stdlib.h>
#include <string.h>

static struct function_context_llvm *context = NULL;

/**
 * @brief           Store a function in the context.
 * @param   name    The name of the function.
 * @param   value   The value of the function.
 * @return          The function context.
*/
void llvm_function_context_store(const char *name, LLVMValueRef value)
{
    logger().llvm("Storing function %s.\n", name);
    struct function_context_llvm *new_context = malloc(sizeof(struct function_context_llvm));

    new_context->name = name;
    new_context->value = value;
    new_context->next = context;
    context = new_context;
}

/**
 * @brief           Get a function from the context.
 * @param   name    The name of the function.
 * @return          The function context.
*/
LLVMValueRef llvm_function_context_get(const char *name)
{
    struct function_context_llvm *current = context;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            logger().llvm("function from context %s found.\n", name);
            return current->value;
        }
        current = current->next;
    }
    logger().llvm("function from context %s not found.\n", name);
    return NULL;
}
