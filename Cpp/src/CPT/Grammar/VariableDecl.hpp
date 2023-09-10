#ifndef __CPT_GRAMMAR_VariableDecl_HPP__
#define __CPT_GRAMMAR_VariableDecl_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT
{
    namespace Grammar
    {
        class VariableDecl : public Packrat::IExpr
        {
        public:
            VariableDecl(): t(nullptr), identifier(""), value(nullptr) {};
            VariableDecl(Type *type, std::string identifier, Packrat::IExpr *value): t(type), identifier(identifier), value(value) {};
            enum cpt_type type() override { return CPT_VARDECL; };
            struct result *parse(Packrat::Parser &p);
            Type *getType() { return t; };
            std::string get() { return identifier; };
            Packrat::IExpr *getValue() { return value; };

        private:
            Type *t;
            std::string identifier;
            Packrat::IExpr *value;
        };
    } // namespace Grammar

} // namespace CPT

#endif
