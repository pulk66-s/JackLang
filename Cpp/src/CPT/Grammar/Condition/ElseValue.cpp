#include "CPT/Grammar/Condition/ElseValue.hpp"
#include "CPT/Grammar/Condition/If.hpp"
#include "CPT/Grammar/Condition/Body.hpp"
#include "CPT/Grammar/Condition/Condition.hpp"
#include "IO.hpp"

namespace CPT::Grammar::Cond
{
    struct result *ElseValue::parse(Packrat::Parser &p)
    {
        IO::Logger::cpt_debug("\"ElseValue\": {\n");
        p.save();
        struct result *res = Packrat::ordered_choice(p, {
            new Condition(),
            new Body()
        });
        if (!res) {
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            p.rollback();
            return nullptr;
        }
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        p.commit();
        return res;
    }
} // namespace CPT::Grammar::Cond
