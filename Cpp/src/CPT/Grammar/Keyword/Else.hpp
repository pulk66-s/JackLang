#ifndef __CL_GRAMMAR_KEYWORD_ELSE_HPP__
#define __CL_GRAMMAR_KEYWORD_ELSE_HPP__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"
#include "CPT/Grammar/Keyword/AKeyword.hpp"
#include "IO.hpp"

namespace CPT::Grammar::Keyword
{
    class Else : public AKeyword {
    public:
        Else() : AKeyword("else") {};
    };
} // namespace CPT::Grammar::Keyword

#endif
