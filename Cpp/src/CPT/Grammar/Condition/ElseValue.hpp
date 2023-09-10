#ifndef __CL_CPT_GRAMMAR_CONDITION_ELSEVALUE_HPP__
#define __CL_CPT_GRAMMAR_CONDITION_ELSEVALUE_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT::Grammar::Cond
{
    class ElseValue : public Packrat::IExpr {
    public:
        struct result *parse(Packrat::Parser &p);
        enum cpt_type type() { return CPT_UNKNOWN; };
    };
} // namespace CPT::Grammar::Cond

#endif
