#include "CPT/Grammar/Variable.hpp"
#include "CPT/Grammar/Type.hpp"
#include "CPT/Grammar/Identifier.hpp"
#include "CPT/Grammar/Number.hpp"
#include "CPT/Grammar/SpecialChar.hpp"
#include "CPT/Packrat.hpp"
#include "IO.hpp"
#include <iostream>

namespace CPT
{
    namespace Grammar
    {
        struct result *Variable::parse(Packrat::Parser &p)
        {
            p.save();
            IO::Logger::cpt_debug("\"Variable\": {\n");

            struct result *r = Packrat::sequence(p, {
                new Type(),
                new Identifier(),
                new SpecialChar('='),
                new Number()
            });
            struct result *ret = new struct result;
            Type *t = (Type *)r->exprs[0];
            Identifier *i = (Identifier *)r->exprs[1];
            Number *n = (Number *)r->exprs[3];

            if (!r) {
                p.rollback();
                IO::Logger::cpt_debug("\"end\": \"fail\"}\n");
                return nullptr;
            }
            ret->exprs.push_back(new Variable(t, i->get(), n));
            IO::Logger::cpt_debug("\"end\": \"success\"},\n");
            return ret;
        }
    } // namespace Grammar
} // namespace CPT
