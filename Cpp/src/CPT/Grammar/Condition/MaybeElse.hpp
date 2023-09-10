#ifndef __CL_CPT_GRAMMAR_CONDITION_MAYBEELSE_HPP__
#define __CL_CPT_GRAMMAR_CONDITION_MAYBEELSE_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT::Grammar::Cond
{
    class MaybeElse : public Packrat::IExpr {
    public:
        enum cpt_type type() { return CPT_COND; };
        struct result *parse(Packrat::Parser &p);
    };
} // namespace CPT::Grammar::Cond


#endif