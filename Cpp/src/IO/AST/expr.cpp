#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"
#include "AST.hpp"

namespace IO::AST_log
{
    void printExpr(AST::IExpr *expr)
    {
        switch (expr->type()) {
        case AST::AST_VARDECL:
            printVarDecl((AST::VarDecl *)expr);
            break;
        case AST::AST_COND:
            printCondition((AST::Condition *)expr);
            break;
        default:
            IO::Logger::ast("\"message\": \"Unknown type '%d'\",\n", expr->type());
            break;
        }
    }

    void printExprValue(AST::IExpr *value)
    {
        switch (value->type()) {
            case AST::AST_CONSTANT:
                printConstant((AST::Constant *)value);
                break;
            default:
                IO::Logger::ast("\"message\": \"Unknown type '%d'\",\n", value->type());
                break;
        }
    }
} // namespace IO::AST_log
