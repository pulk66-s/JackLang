#ifndef __CL_CPT_CPTNAMESPACE_HPP__
#define __CL_CPT_CPTNAMESPACE_HPP__

#include <vector>
#include <functional>
#include <string>

namespace CPT {
    enum cpt_type {
        CPT_NUMBER,
        CPT_PROGRAM,
        CPT_TYPE,
        CPT_VARIABLE,
        CPT_IDENTIFIER,
        CPT_CHAR
    };
    namespace Packrat {
        class Parser;
        class IExpr;
    };
    struct result {
        std::vector<Packrat::IExpr *> exprs;
    };

    namespace Packrat {
        int *number(Parser &p);
        std::string word(Parser &p);
        std::string identifier(Parser &p);
        std::string keyword(Parser &p, std::string keyword);
        char character(Parser &p, char c);
        bool isAlpha(char c);
        bool isDigit(char c);
        bool isAlphaNum(char c);
        struct result *sequence(Parser &p, std::vector<IExpr *> exprs);
    }; // namespace Packrat
    namespace Grammar
    {
        class Number;
        class Program;
        class Type;
        class Variable;
        class SpecialChar;
    }; // namespace Grammar
};

#endif
