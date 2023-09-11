#ifndef __CL_AST_TYPE_INT_HPP__
#define __CL_AST_TYPE_INT_HPP__

#include "AST/ASTNamespace.hpp"
#include "AST/Type.hpp"

namespace AST::Type
{
    class Int : public IType {
    public:
        Int(int base): base(base) {};
        int get_base() { return base; };
        std::string getName() const  { return "int" + std::to_string(base); };

    private:
        int base;
    };
} // namespace AST::Type

#endif
