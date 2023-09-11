#ifndef __CL_CPT_CPTNAMESPACE_HPP__
#define __CL_CPT_CPTNAMESPACE_HPP__

#include <vector>
#include <functional>
#include <string>

namespace CPT {
    enum cpt_type {
        CPT_UNKNOWN,
        CPT_NUMBER,
        CPT_PROGRAM,
        CPT_TYPE,
        CPT_VARDECL,
        CPT_IDENTIFIER,
        CPT_CHAR,
        CPT_FN_DECL,
        CPT_COND,
        CPT_KEYWORD
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
        struct result *zero_or_more(Parser &p, IExpr *expr);
        struct result *zero_or_one(Parser &p, IExpr *expr);
        struct result *ordered_choice(Parser &p, std::vector<IExpr *> exprs);
    }; // namespace Packrat

    namespace Grammar
    {
        class Number;
        class Program;
        class Type;
        class VariableDecl;
        class SpecialChar;
        class FunctionDecl;
        class FunctionLines;
        class FunctionLine;
        class Statement;
        class Condition;
        class Value;
        class MaybeValue;
        class Identifier;

        namespace Cond
        {
            class If;
            class Else;
            class Body;
            class ElseValue;
            class MaybeElse;
        } // namespace Cond
        

        namespace Keyword
        {
            class AKeyword;
            class If;
            class Else;
        } // namespace Keyword
    }; // namespace Grammar
};

#endif
