#ifndef __CL_AST_TYPE_HPP__
#define __CL_AST_TYPE_HPP__

#include "CPT.hpp"
#include "AST/ASTNamespace.hpp"
#include <string>

namespace AST
{
    class IType {
    public:
        virtual ~IType() = default;
        static IType *createType(CPT::Grammar::Type *type);
        virtual std::string getName() const = 0;
    };
} // namespace AST

#endif
