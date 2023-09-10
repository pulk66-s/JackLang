#include "CPT/Grammar/Condition/Body.hpp"
#include "CPT/Grammar/Function/FunctionLines.hpp"
#include "IO.hpp"

namespace CPT::Grammar::Cond
{
    struct result *Body::parse(Packrat::Parser &p)
    {
        IO::Logger::cpt_debug("\"Body\": {\n");
        p.save();
        struct result *res = Packrat::sequence(p, {
            new SpecialChar('{'),
            new FunctionLines(),
            new SpecialChar('}'),
        });
        struct result *ret = new struct result;
        if (!res) {
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            p.rollback();
            return nullptr;
        }
        ret->exprs = {res->exprs[1]};
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        p.commit();
        return ret;
    }
} // namespace CPT::Grammar::Cond
