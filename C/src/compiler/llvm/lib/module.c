#include "compiler/llvm/lib/module.h"
#include <stdlib.h>

/**
 * @brief           Create a new LLVM module with the given name.
 * @param   name    The name of the module.
 * @return          The LLVM module.
*/
LLVMModuleRef create_llvm_module_wname(const char *name)
{
    return LLVMModuleCreateWithName(name);
}

/**
 * @brief   Create a new LLVM module with the default name.
 * @return  The LLVM module.
*/
LLVMModuleRef create_default_llvm_module(void)
{
    return create_llvm_module_wname("start");
}

/**
 * @brief           Output the content of the LLVM module to the given file.
 * @param   module  The LLVM module.
 * @param   file    The file path to output to.
*/
void output_llvm_module(LLVMModuleRef module, const char *file_path)
{
    LLVMPrintModuleToFile(module, file_path, NULL);
}