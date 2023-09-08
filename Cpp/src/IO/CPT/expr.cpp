#include <iostream>
#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"

namespace IO
{
    namespace CPT_log
    {
        void printExpr(CPT::Packrat::IExpr *expr)
        {
            switch (expr->type()) {
            case CPT::CPT_PROGRAM:
                printPrgm((CPT::Grammar::Program *)expr);
                break;
            case CPT::CPT_NUMBER:
                printNb((CPT::Grammar::Number *)expr);
                break;
            case CPT::CPT_IDENTIFIER:
                printIdentifier((CPT::Grammar::Identifier *)expr);
                break;
            case CPT::CPT_VARIABLE:
                printVar((CPT::Grammar::Variable *)expr);
                break;
            case CPT::CPT_CHAR:
                printChar((CPT::Grammar::SpecialChar *)expr);
                break;
            case CPT::CPT_TYPE:
                printType((CPT::Grammar::Type *)expr);
                break;
            default:
                Logger::cpt("{\"fail\": \"Unknown expression type %d\"}", expr->type());
                break;
            }
        }

        void printExprs(std::vector<CPT::Packrat::IExpr *> exprs)
        {
            Logger::cpt("\"exprs\": [\n");
            for (CPT::Packrat::IExpr *expr : exprs) {
                printExpr(expr);
            }
            Logger::cpt("],\n");
        }
    } // namespace CPT_
} // namespace IO
