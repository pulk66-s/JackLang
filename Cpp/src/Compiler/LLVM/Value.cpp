#include "Compiler/LLVM/Value.hpp"
#include <iostream>

namespace Comp::LLVM
{
    Value::Value(AST::IExpr *expr, Lib::Context *ctx)
    {
        switch (expr->type()) {
        case AST::AST_CONSTANT:
            this->value = new Lib::Value(Constant(static_cast<AST::Constant *>(expr), ctx).get()->get());
            break;
        default:
            std::cout << "Unknown value expr type " << expr->type() << std::endl;
            break;
        }
    }
} // namespace Comp::LLVM
