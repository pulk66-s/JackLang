/**
 * Identifier Grammar Header
 * See the Documentation (doc/code/Grammar/Identifier.md)
*/

#ifndef __CPT_GRAMMAR_IDENTIFIER_HPP__
#define __CPT_GRAMMAR_IDENTIFIER_HPP__

#include "CPT/Packrat.hpp"
#include "CPT/CPTNamespace.hpp"
#include <string>

namespace CPT::Grammar
{
    class Identifier : public Packrat::IExpr
    {
    public:
        Identifier(): identifier("") {};
        Identifier(std::string identifier): identifier(identifier) {};
        struct result *parse(Packrat::Parser &p);
        enum cpt_type type() { return CPT_IDENTIFIER; };
        std::string get() { return identifier; };
    private:
        std::string identifier;
    };
} // namespace CPT

#endif
