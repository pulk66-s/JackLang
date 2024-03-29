#ifndef __CL_IO_IONAMESPACE_HPP__
#define __CL_IO_IONAMESPACE_HPP__

#include "CPT/CPTNamespace.hpp"
#include "AST/ASTNamespace.hpp"

namespace IO {
    class File;
    class Logger;
    namespace CPT_log {
        void printExpr(CPT::Packrat::IExpr *expr);
        void printExprs(std::vector<CPT::Packrat::IExpr *> exprs);
        void printPrgm(CPT::Grammar::Program *prgm);
        void printNb(CPT::Grammar::Number *nb);
        void printIdentifier(CPT::Grammar::Identifier *id);
        void printChar(CPT::Grammar::SpecialChar *c);
        void printType(CPT::Grammar::Type *type);
        void printVar(CPT::Grammar::VariableDecl *var);
        void printFnDecl(CPT::Grammar::FunctionDecl *fn);
        void printCond(CPT::Grammar::Condition *cond);
        void printKeyword(CPT::Grammar::Keyword::AKeyword *kw);
    };

    namespace AST_log {
        void printPrgm(AST::Program *prgm);
        void printFnDecl(AST::FunctionDecl *fn);
        void printBlock(AST::Block *block);
        void printVarDecl(AST::VarDecl *var);
        void printConstant(AST::Constant *c);
        void printCondition(AST::Condition *cond);
        void printExpr(AST::IExpr *expr);
        void printExprValue(AST::IExpr *value);
    };
};

#endif
