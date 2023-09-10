#ifndef __CL_CPT_GRAMMAR_FUNCTION_LINE_HPP__
#define __CL_CPT_GRAMMAR_FUNCTION_LINE_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"
#include <vector>

namespace CPT::Grammar
{
    class FunctionLine : public Packrat::IExpr {
    public:
        FunctionLine() {};
        FunctionLine(Packrat::IExpr *line): line(line) {};
        struct result *parse(Packrat::Parser &p);
        enum cpt_type type() { return CPT_UNKNOWN; };
        Packrat::IExpr *get_line() { return line; };

    private:
        Packrat::IExpr *line = nullptr;
    };
} // namespace CPT::Grammar


#endif