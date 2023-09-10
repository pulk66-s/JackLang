#ifndef __CL_CPT_GRAMMAR_MAYBEVALUE_HPP__
#define __CL_CPT_GRAMMAR_MAYBEVALUE_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT::Grammar
{
    class MaybeValue : public Packrat::IExpr {
    public:
        enum cpt_type type() { return CPT_UNKNOWN; };
        struct result *parse(Packrat::Parser &p);
    };
} // namespace CPT::Grammar


#endif