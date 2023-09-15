#include "CPT/Grammar/Value.hpp"
#include "CPT/Grammar/Number.hpp"
#include "CPT/Grammar/Identifier.hpp"
#include "IO.hpp"

namespace CPT::Grammar
{
    struct result *Value::parse(Packrat::Parser &p)
    {
        IO::Logger::cpt_debug("\"Value\": {\n");
        p.save();
        struct result *res = Packrat::ordered_choice(p, {
            new Number(),
            new Identifier(),
        });
        if (!res) {
            IO::Logger::cpt_debug("\"end\": \"fail\",},\n");
            p.rollback();
            return nullptr;
        }
        p.commit();
        IO::Logger::cpt_debug("\"end\": \"success\",},\n");
        return res;
    }
} // namespace CPT::Grammar
