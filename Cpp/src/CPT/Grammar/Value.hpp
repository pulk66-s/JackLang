#ifndef __CL_CPT_GRAMMAR_VALUE_HPP__
#define __CL_CPT_GRAMMAR_VALUE_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT::Grammar
{
    class Value : public Packrat::IExpr {
    public:
        Value() {};
        enum cpt_type type() { return CPT::CPT_UNKNOWN; };
        struct result *parse(Packrat::Parser &p);
    };
} // namespace CPT::Grammar

#endif
