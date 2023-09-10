#include "CPT/Grammar/MaybeValue.hpp"
#include "IO.hpp"
#include "CPT/Packrat.hpp"
#include "CPT/Grammar/Value.hpp"

namespace CPT::Grammar
{
    struct result *MaybeValue::parse(Packrat::Parser &p)
    {
        IO::Logger::cpt_debug("\"MaybeValue\": {\n");
        struct result *res = Packrat::zero_or_one(p, new Value());
        if (res->exprs.size() == 0) {
            res->exprs = {new MaybeValue()};
        }
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        return res;
    }
} // namespace CPT::Grammar
