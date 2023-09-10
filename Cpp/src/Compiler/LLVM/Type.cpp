#include "Compiler/LLVM/Type.hpp"
#include <unordered_map>
#include <iostream>

namespace Comp::LLVM
{
    void Type::createInt32(Lib::Context *ctx)
    {
        this->type = new Lib::Type(Lib::Type::getIntTy(ctx, 32));
    }

    Type::Type(AST::IType *type, Lib::Context *ctx)
    {
        std::string typeName = type->getName();
        std::unordered_map<std::string, void (Type::*)(Lib::Context *)> typeMap = {
            {"int32", &Type::createInt32}
        };

        if (typeMap.find(typeName) != typeMap.end()) {
            (this->*typeMap[typeName])(ctx);
        } else {
            std::cout << "Unknown type: " << typeName << std::endl;
        }
    }
} // namespace Comp::LLVM
