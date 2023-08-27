#ifndef __CL_COMPILER_LLVM_LIB_MODULE_H__
#define __CL_COMPILER_LLVM_LIB_MODULE_H__

#include <llvm-c/Core.h>

/**
 * @brief           Create a new LLVM module with the given name.
 * @param   name    The name of the module.
 * @return          The LLVM module.
*/
LLVMModuleRef create_llvm_module_wname(const char *name);

/**
 * @brief   Create a new LLVM module with the default name.
 * @return  The LLVM module.
*/
LLVMModuleRef create_default_llvm_module(void);

/**
 * @brief           Output the content of the LLVM module to the given file.
 * @param   module  The LLVM module.
 * @param   file    The file path to output to.
*/
void output_llvm_module(LLVMModuleRef module, const char *file_path);

#endif