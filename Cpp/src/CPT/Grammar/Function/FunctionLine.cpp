#include "CPT/Grammar/Function/FunctionLine.hpp"
#include "CPT/Grammar/Statement.hpp"
#include "CPT/Grammar/Condition.hpp"
#include "CPT/Packrat.hpp"
#include "IO.hpp"

namespace CPT::Grammar
{
    struct result *FunctionLine::parse(Packrat::Parser &p)
    {
        p.save();
        IO::Logger::cpt_debug("\"FunctionLine\": {\n");

        struct result *res = ordered_choice(p, {
            new Statement(),
            new Condition(),
        });
        struct result *ret = new struct result;

        if (!res) {
            p.rollback();
            IO::Logger::cpt_debug("\"message\": \"Choice is null\",\n");
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            return nullptr;
        }
        ret->exprs = {new FunctionLine(res->exprs[0])};
        p.commit();
        IO::Logger::cpt_debug("\"message\": \"Choice is %d\",\n", res->exprs[0]->type());
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        return ret;
    }
} // namespace CPT::Grammar
