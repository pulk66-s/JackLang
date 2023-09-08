#ifndef __CL_CPT_GRAMMAR_NUMBER_HPP__
#define __CL_CPT_GRAMMAR_NUMBER_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT
{
    namespace Grammar
    {
        class Number : public Packrat::IExpr
        {
        public:
            Number(): value(0) {};
            Number(int value);
            struct result *parse(Packrat::Parser &p);
            int get();
            enum cpt_type type() { return CPT_NUMBER; }

        private:
            int value;
        };
    }; // namespace Grammar
};     // namespace CPT

#endif
