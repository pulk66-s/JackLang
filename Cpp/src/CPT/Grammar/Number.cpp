/**
 * Number Grammar implementation
 * See the Documentation (doc/code/Grammar/Number.md)
*/

#include "CPT/Grammar/Number.hpp"
#include "CPT/Packrat.hpp"
#include "CPT/Grammar/SpecialChar.hpp"
#include "IO.hpp"

namespace CPT::Grammar
{
    struct result *Number::parse(Packrat::Parser &p)
    {
        IO::Logger::cpt_debug("\"Number\": {\n");
        p.save();

        int signValue = 1;
        struct result *sign = Packrat::ordered_choice(p, {
            new SpecialChar('+'),
            new SpecialChar('-'),
        });

        if (!sign) {
            p.rollback();
            p.save();
        } else {
            SpecialChar *sc = (SpecialChar *)sign->exprs[0];
            if (sc->get() == '-') {
                signValue = -1;
            }
        }

        struct result *res = new struct result;
        int *value = Packrat::number(p);

        if (value == nullptr) {
            IO::Logger::cpt_debug("\"end\": \"fail\",\n");
            IO::Logger::cpt_debug("\"reason\": \"Number is null\"},\n");
            p.rollback();
            return nullptr;
        }
        *value = *value * signValue;
        res->exprs = {};
        res->exprs.push_back(new Number(*value));
        p.commit();
        IO::Logger::cpt_debug("\"data\": %d,\n", *value);
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        return res;
    }
};     // namespace CPT
