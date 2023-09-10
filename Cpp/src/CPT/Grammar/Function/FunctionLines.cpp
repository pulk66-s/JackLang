#include "CPT/Grammar/Function/FunctionLines.hpp"
#include "CPT/Grammar/Function/FunctionLine.hpp"
#include "IO.hpp"

namespace CPT::Grammar
{
    struct result *FunctionLines::parse(Packrat::Parser &p)
    {
        p.save();
        IO::Logger::cpt_debug("\"FunctionLines\": {\n");

        struct result *res = zero_or_more(p, new FunctionLine());
        struct result *ret = new struct result;

        for (Packrat::IExpr *expr : res->exprs) {
            IO::Logger::cpt_debug("\"line\": %d,\n", ((FunctionLine *)expr)->get_line()->type());
            this->lines.push_back(((FunctionLine *)expr)->get_line());
        }
        IO::Logger::cpt_debug("\"size\": %d,\n", this->lines.size());
        ret->exprs = {new FunctionLines(this->lines)};
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        p.commit();
        return ret;
    }
} // namespace CPT::Grammar
