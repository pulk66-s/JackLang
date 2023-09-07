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
            virtual ~IExpr() = default;
            virtual enum cpt_type type() = 0;
        };
    }; // namespace Packrat
};     // namespace CPT

#endif

