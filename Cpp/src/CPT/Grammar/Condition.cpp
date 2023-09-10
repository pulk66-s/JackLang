#include "CPT/Grammar/Condition.hpp"
#include "CPT/Grammar/Keyword.hpp"
#include "CPT/Grammar/Function/FunctionLines.hpp"
#include "CPT/Grammar/MaybeValue.hpp"
#include "IO.hpp"
#include <iostream>

namespace CPT::Grammar
{
    struct result *Condition::parse(Packrat::Parser &p)
    {
        IO::Logger::cpt_debug("\"Condition\": {\n");
        p.save();

        struct result *res = sequence(p, {
            new Keyword::If(),
            new SpecialChar('('),
            new MaybeValue(),
            new SpecialChar(')'),
            new SpecialChar('{'),
            new FunctionLines(),
            new SpecialChar('}')
        });
        struct result *ret = new struct result;
        if (!res) {
            IO::Logger::cpt_debug("\"end\": \"fail\",},\n");
            p.rollback();
            return nullptr;
        }
        FunctionLines *lines = dynamic_cast<FunctionLines *>(res->exprs[5]);

        if (!res) {
            IO::Logger::cpt_debug("\"end\": \"fail\",},\n");
            p.rollback();
            return nullptr;
        }
        ret->exprs = {
            new Condition(
                res->exprs[2]->type() == 0 ? nullptr : res->exprs[2], 
                lines->get_lines(), {}
            )
        };
        IO::Logger::cpt_debug("\"end\": \"success\",},\n");
        p.commit();
        return ret;
    }
} // namespace CPT::Grammar
