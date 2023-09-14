/**
 * Number Grammar Prototype
 * See the Documentation (doc/code/Grammar/Number.md)
*/

#ifndef __CL_CPT_GRAMMAR_NUMBER_HPP__
#define __CL_CPT_GRAMMAR_NUMBER_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT::Grammar
{
    class Number : public Packrat::IExpr
    {
    public:
        Number(): value(0) {};
        Number(int value): value(value) {};
        struct result *parse(Packrat::Parser &p);
        int get() { return value; };
        enum cpt_type type() { return CPT_NUMBER; }

    private:
        int value;
    };
};     // namespace CPT

#endif
