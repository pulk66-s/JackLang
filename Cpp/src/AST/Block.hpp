#ifndef __CL_AST_BLOCK_HPP__
#define __CL_AST_BLOCK_HPP__

#include "AST/ASTNamespace.hpp"
#include "AST/Expr.hpp"
#include "CPT.hpp"
#include <vector>

namespace AST
{
    class Block {
    public:
        Block(std::vector<CPT::Packrat::IExpr *> lines);
        std::vector<IExpr *> getLines() const { return this->lines; };

    private:
        std::vector<IExpr *> lines = {};
    };
} // namespace AST

#endif