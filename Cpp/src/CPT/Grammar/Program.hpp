#ifndef __CL_CPT_GRAMMAR_PROGRAM_HPP__
#define __CL_CPT_GRAMMAR_PROGRAM_HPP__

#include "CPT/Packrat.hpp"
#include <vector>
#include <functional>

namespace CPT::Grammar
{
    class Program : public Packrat::IExpr {
    public:
        Program(): exprs({}) {}
        Program(std::vector<Packrat::IExpr *> exprs): exprs(exprs) {}
        struct result *parse(Packrat::Parser &p);
        struct result *parse(Packrat::Parser &p, std::function<struct result *(Packrat::Parser &)> f);
        enum cpt_type type()  { return CPT_PROGRAM; }
        std::vector<Packrat::IExpr *> get() { return exprs; }

    private:
        std::vector<Packrat::IExpr *> exprs;
    };
} // namespace CPT

#endif
