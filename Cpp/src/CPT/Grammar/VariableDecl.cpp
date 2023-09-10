#include "CPT/Grammar/VariableDecl.hpp"
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
        struct result *VariableDecl::parse(Packrat::Parser &p)
        {
            p.save();
            IO::Logger::cpt_debug("\"VariableDecl\": {\n");
            IO::Logger::cpt_debug("\"start_cursor\": \"%d %d %d\",\n", p.getPos().x, p.getPos().y, p.getPos().z);

            struct result *r = Packrat::sequence(p, {
                new Type(),
                new Identifier(),
                new SpecialChar('='),
                new Number()
            });
            struct result *ret = new struct result;

            if (!r) {
                p.rollback();
                IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
                return nullptr;
            }

            Type *t = (Type *)r->exprs[0];
            Identifier *i = (Identifier *)r->exprs[1];
            Number *n = (Number *)r->exprs[3];

            ret->exprs.push_back(new VariableDecl(t, i->get(), n));
            IO::Logger::cpt_debug("\"end\": \"success\"},\n");
            return ret;
        }
    } // namespace Grammar
} // namespace CPT
