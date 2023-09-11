#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"
#include "AST.hpp"

namespace IO::AST_log
{
    void printCondition(AST::Condition *cond)
    {
        IO::Logger::ast("\"Condition\": {\n");
        IO::Logger::ast("\"condition\": {\n");
        if (cond->getCondition()) {
            printExpr(cond->getCondition());
        }
        IO::Logger::ast("},\n");
        IO::Logger::ast("\"trueBlock\": {\n");
        if (cond->getTrueBlock()) {
            printBlock(cond->getTrueBlock());
        }
        IO::Logger::ast("},\n");
        IO::Logger::ast("\"falseBlock\": {\n");
        if (cond->getFalseBlock()) {
            printBlock(cond->getFalseBlock());
        }
        IO::Logger::ast("},\n");
        IO::Logger::ast("},\n");
    }
} // namespace IO::AST_log
