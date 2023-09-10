#ifndef __CL_CPT_GRAMMAR_CONDITION_ELSE_HPP__
#define __CL_CPT_GRAMMAR_CONDITION_ELSE_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"
#include <vector>

namespace CPT::Grammar::Cond
{
    class Else : public Packrat::IExpr {
    public:
        Else() {};
        Else(std::vector<Packrat::IExpr *> then) : then(then) {};
        enum cpt_type type() { return CPT_COND; };
        struct result *parse(Packrat::Parser &p);
        std::vector<Packrat::IExpr *> get() { return then; };
    private:
        std::vector<Packrat::IExpr *> then = {};
    };
} // namespace CPT::Grammar::Cond

#endif
