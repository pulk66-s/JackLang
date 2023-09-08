#ifndef __CL_CPT_PACKRAT_EXPR_HPP__
#define __CL_CPT_PACKRAT_EXPR_HPP__

#include "CPT/CPTNamespace.hpp"

namespace CPT
{
    namespace Packrat
    {
        class IExpr
        {
        public:
            virtual enum cpt_type type() = 0;
            virtual struct result *parse(Packrat::Parser &p) = 0;
        };
    }; // namespace Packrat
};     // namespace CPT

#endif

