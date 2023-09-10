#ifndef __CL_CPP_GRAMMAR_FUNCTION_FUNCTIONDECL_HPP__
#define __CL_CPP_GRAMMAR_FUNCTION_FUNCTIONDECL_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Grammar/Type.hpp"
#include "CPT/Grammar/Identifier.hpp"
#include "CPT/Packrat.hpp"

namespace CPT::Grammar
{
    class FunctionDecl : public Packrat::IExpr {
    public:
        FunctionDecl(): t(nullptr), identifier(nullptr) {};
        FunctionDecl(Type *type, Identifier *identifier, std::vector<Packrat::IExpr *> lines): t(type), identifier(identifier), lines(lines) {};
        enum cpt_type type() { return CPT_FN_DECL; };
        struct result *parse(CPT::Packrat::Parser &p);
        Type *get_type() { return t; };
        Identifier *get_identifier() { return identifier; };
        std::vector<Packrat::IExpr *> get_lines() { return lines; };

    private:
        Type *t;
        Identifier *identifier;
        std::vector<Packrat::IExpr *> lines = {};
    };
} // namespace CPT::Grammar

#endif
