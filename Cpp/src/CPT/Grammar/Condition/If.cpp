#include "CPT/Grammar/Condition/If.hpp"
#include "CPT/Grammar/Condition/Body.hpp"
#include "CPT/Grammar/Keyword.hpp"
#include "CPT/Grammar/MaybeValue.hpp"
#include "CPT/Grammar/SpecialChar.hpp"
#include "CPT/Grammar/Function/FunctionLines.hpp"
#include "IO.hpp"
#include <iostream>

namespace CPT::Grammar::Cond
{
    struct result *If::parse(Packrat::Parser &p)
    {
        IO::Logger::cpt_debug("\"If\": {\n");
        p.save();

        struct result *res = Packrat::sequence(p, {
            new Keyword::If(),
            new SpecialChar('('),
            new MaybeValue(),
            new SpecialChar(')'),
            new Body(),
        });
        struct result *ret = new struct result;
        if (!res) {
            IO::Logger::cpt_debug("\"end\": \"fail\",},\n");
            p.rollback();
            return nullptr;
        }
        FunctionLines *lines = dynamic_cast<FunctionLines *>(res->exprs[4]);

        if (!res) {
            IO::Logger::cpt_debug("\"end\": \"fail\",},\n");
            p.rollback();
            return nullptr;
        }
        ret->exprs = {new If(res->exprs[2]->type() == CPT_UNKNOWN ? nullptr : res->exprs[2], lines->get_lines())};
        p.commit();
        IO::Logger::cpt_debug("\"end\": \"success\",},\n");
        return ret;
    }
} // namespace CPT::Grammar::Cond
