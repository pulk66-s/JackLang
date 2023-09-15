#ifndef __CL_CPT_GRAMMAR_SPECIALCHAR_HPP__
#define __CL_CPT_GRAMMAR_SPECIALCHAR_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT::Grammar
{
    class SpecialChar : public Packrat::IExpr
    {
    public:
        SpecialChar(char c) : c(c) {};
        struct result *parse(Packrat::Parser &p);
        enum cpt_type type()  { return CPT_CHAR; };
        char get() { return c; };
    private:
        char c;
    };
} // namespace CPT

#endif
