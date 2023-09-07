#ifndef __CL_CPT_CPTNAMESPACE_HPP__
#define __CL_CPT_CPTNAMESPACE_HPP__

#include <vector>
#include <functional>

namespace CPT {
    namespace Packrat {
        class Parser;
        class IExpr;
        int *number(Parser &p);
    }; // namespace Packrat
    namespace Grammar
    {
        class Number;
        class Program;
    }; // namespace Grammar

    enum cpt_type {
        CPT_NUMBER,
        CPT_PROGRAM
    };
    struct result {
        enum cpt_type type;
        std::vector<Packrat::IExpr *> exprs;
    };
};

#endif
