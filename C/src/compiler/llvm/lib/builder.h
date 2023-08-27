#ifndef __CL_COMPILER_LLVM_LIB_BUILDER_H__
#define __CL_COMPILER_LLVM_LIB_BUILDER_H__

#include <llvm-c/Core.h>

/**
 * @brief           Create a default builder for the given module.
 * @param   module  The module to create the builder for.
 * @return          The created builder.
 */
LLVMBuilderRef create_default_llvm_builder(LLVMModuleRef module);

#endif
