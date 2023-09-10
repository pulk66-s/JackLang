#include "CPT/Grammar/Keyword.hpp"
#include "CPT/Grammar/Condition/Else.hpp"
#include "CPT/Grammar/Condition/ElseValue.hpp"
#include "CPT/Grammar/Function.hpp"
#include "IO.hpp"

namespace CPT::Grammar::Cond
{
    struct result *Else::parse(Packrat::Parser &p)
    {
        IO::Logger::cpt_debug("\"Else\": {\n");
        p.save();
        struct result *res = Packrat::sequence(p, {
            new Keyword::Else(),
            new ElseValue()
        });
        struct result *ret = new struct result();
        if (!res) {
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            p.rollback();
            return nullptr;
        }
        Packrat::IExpr *expr = dynamic_cast<Packrat::IExpr *>(res->exprs[1]);
        if (expr->type() == CPT_COND) {
            IO::Logger::cpt_debug("\"message\": \"else is a condition\",\n");
            this->then.push_back(expr);
        } else {
            IO::Logger::cpt_debug("\"message\": \"else is a line\",\n");
            this->then = ((FunctionLines *)expr)->get_lines();
        }
        IO::Logger::cpt_debug("\"body_size\": \"%d\",\n", res->exprs.size());
        IO::Logger::cpt_debug("\"then size\": \"%d\",\n", this->then.size());
        IO::Logger::cpt_debug("\"then first type\": \"%d\",\n", this->then[0]->type());
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        ret->exprs = {new Else(this->then)};
        p.commit();
        return ret;
    }
} // namespace CPT::Grammar::Cond
