#include "CPT/Grammar/Condition/MaybeElse.hpp"
#include "CPT/Grammar/Condition/Else.hpp"
#include "IO.hpp"

namespace CPT::Grammar::Cond
{
    struct result *MaybeElse::parse(Packrat::Parser &p)
    {
        IO::Logger::cpt_debug("\"MaybeElse\": {\n");
        p.save();
        struct result *res = Packrat::zero_or_one(p, new Else());
        if (!res) {
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            p.rollback();
            return nullptr;
        }
        if (res->exprs.size() == 0) {
            IO::Logger::cpt_debug("\"message\": \"no else\",\n");
            IO::Logger::cpt_debug("\"end\": \"success\"},\n");
            p.commit();
            return res;
        }
        IO::Logger::cpt_debug("\"first object type\": \"%d\",\n", res->exprs[0]->type());
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        p.commit();
        return res;
    }
} // namespace CPT::Grammar::Cond
