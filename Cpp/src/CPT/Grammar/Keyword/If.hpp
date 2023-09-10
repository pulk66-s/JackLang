#ifndef __CL_GRAMMAR_KEYWORD_IF__
#define __CL_GRAMMAR_KEYWORD_IF__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"
#include "CPT/Grammar/Keyword/AKeyword.hpp"
#include "IO.hpp"

namespace CPT::Grammar::Keyword
{
    class If : public AKeyword {
    public:
        If() : AKeyword("if") {};
    };
} // namespace CPT::Grammar::Keyword

#endif
