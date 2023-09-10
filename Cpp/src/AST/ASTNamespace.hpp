#ifndef __CL_AST_NAMESPACE_HPP__
#define __CL_AST_NAMESPACE_HPP__

namespace AST
{
    class Program;
    class Block;
    class FunctionDecl;
    class VarDecl;
    class IExpr;
    class Constant;

    class IType;
    namespace Type {
        class Int;
    };

    enum ast_type {
        AST_UNKNOWN,
        AST_VARDECL,
        AST_CONSTANT
    };
} // namespace AST

#endif
