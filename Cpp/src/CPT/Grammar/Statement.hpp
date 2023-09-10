#ifndef __CL_CPT_GRAMMAR_STATEMENT_HPP__
#define __CL_CPT_GRAMMAR_STATEMENT_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT::Grammar
{
    class Statement : public Packrat::IExpr
    {
    public:
        Statement() {};
        Statement(Packrat::IExpr *expr): expr(expr) {}
        struct result *parse(Packrat::Parser &p);
        enum cpt_type type() { return CPT_UNKNOWN; };

    private:
        Packrat::IExpr *expr = nullptr;
    };
} // namespace CPT::Grammar


#endif