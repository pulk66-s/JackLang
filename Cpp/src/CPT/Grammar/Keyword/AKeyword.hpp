#ifndef __CL_GRAMMAR_KEYWORD_AKEYWORD__
#define __CL_GRAMMAR_KEYWORD_AKEYWORD__

#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"

namespace CPT::Grammar::Keyword
{
    class AKeyword : public Packrat::IExpr {
    public:
        AKeyword() {};
        AKeyword(std::string data) : data(data) {};
        struct result *parse(Packrat::Parser &p);
        enum cpt_type type() override { return CPT_KEYWORD; };
        std::string get() { return data; };
    protected:
        std::string data = "";
    };
} // namespace CPT::Grammar::Keyword

#endif
