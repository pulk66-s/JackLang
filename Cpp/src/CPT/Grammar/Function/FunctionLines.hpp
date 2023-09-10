#ifndef __CL_CPT_GRAMMAR_FUNCTION_LINES_HPP__
#define __CL_CPT_GRAMMAR_FUNCTION_LINES_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"
#include <vector>

namespace CPT::Grammar
{
    class FunctionLines : public Packrat::IExpr {
    public:
        FunctionLines() {};
        FunctionLines(std::vector<Packrat::IExpr *> lines): lines(lines) {};
        struct result *parse(Packrat::Parser &p);
        enum cpt_type type() { return CPT_UNKNOWN; };
        std::vector<Packrat::IExpr *> get_lines() { return lines; };

    private:
        std::vector<Packrat::IExpr *> lines = {};
    };
} // namespace CPT::Grammar


#endif