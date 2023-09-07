#ifndef __CL_CPT_GRAMMAR_PROGRAM_HPP__
#define __CL_CPT_GRAMMAR_PROGRAM_HPP__

#include "CPT/Packrat.hpp"
#include <vector>

namespace CPT
{
    namespace Grammar
    {
        class Program : public Packrat::IExpr
        {
        public:
            static struct result *parse(Packrat::Parser &p);
            enum cpt_type type() override { return CPT_PROGRAM; }

        private:
            std::vector<Packrat::IExpr *> exprs;
        };
    } // namespace Grammar

} // namespace CPT

#endif
