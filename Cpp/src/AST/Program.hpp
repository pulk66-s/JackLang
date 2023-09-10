#ifndef __CL_AST_PROGRAM_HPP__
#define __CL_AST_PROGRAM_HPP__

#include "AST/ASTNamespace.hpp"
#include "CPT.hpp"
#include "AST/FunctionDecl.hpp"
#include <vector>

namespace AST
{
    class Program {
    public:
        Program(CPT::Grammar::Program *program);
        std::vector<FunctionDecl *> getFunctions() const { return this->functions; };

    private:
        std::vector<FunctionDecl *> functions = {};
    };
} // namespace AST

#endif
