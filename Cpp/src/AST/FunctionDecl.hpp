#ifndef __CL_AST_FUNCTIONDECL_HPP__
#define __CL_AST_FUNCTIONDECL_HPP__

#include "AST/ASTNamespace.hpp"
#include "AST/Block.hpp"
#include "CPT.hpp"
#include <string>
#include <vector>

namespace AST
{
    class FunctionDecl {
    public:
        FunctionDecl(CPT::Grammar::FunctionDecl *functionDecl);
        std::vector<Block *> getBlocks() const { return blocks; };
        std::string getName() const { return name; };

    private:
        std::string name;
        std::vector<Block *> blocks = {};
    };
} // namespace AST

#endif
