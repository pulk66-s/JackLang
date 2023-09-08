#ifndef __CPT_GRAMMAR_VARIABLE_HPP__
#define __CPT_GRAMMAR_VARIABLE_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT
{
    namespace Grammar
    {
        class Variable : public Packrat::IExpr
        {
        public:
            Variable(): t(nullptr), identifier(""), value(nullptr) {};
            Variable(Type *type, std::string identifier, Packrat::IExpr *value): t(type), identifier(identifier), value(value) {};
            enum cpt_type type() override { return CPT_VARIABLE; };
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
