#include <iostream>
#include "CPT/Grammar/Condition/Condition.hpp"
#include "CPT/Grammar/Condition/If.hpp"
#include "CPT/Grammar/Condition/Else.hpp"
#include "CPT/Grammar/Condition/MaybeElse.hpp"
#include "IO.hpp"

namespace CPT::Grammar
{
    struct result *Condition::parse(Packrat::Parser &p)
    {
        IO::Logger::cpt_debug("\"Condition\": {\n");
        p.save();
        struct result *res = Packrat::sequence(p, {
            new Cond::If(),
            new Cond::MaybeElse()
        });
        struct result *ret = new struct result();
        if (!res) {
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            p.rollback();
            return nullptr;
        }
        Cond::If *if_ = dynamic_cast<Cond::If *>(res->exprs[0]);
        Cond::Else *else_ = res->exprs.size() == 1 ? nullptr : dynamic_cast<Cond::Else *>(res->exprs[1]);
        if (else_) {
            IO::Logger::cpt_debug("\"message\": \"else exists\",\n");
            ret->exprs = {new Condition(if_->get_cond(), if_->get(), else_->get())};
        } else {
            IO::Logger::cpt_debug("\"message\": \"else doesn't exists\",\n");
            ret->exprs = {new Condition(if_->get_cond(), if_->get(), {})};
        }
        p.commit();
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        return ret;
    }
} // namespace CPT::Grammar::Cond
