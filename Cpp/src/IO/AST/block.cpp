#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"
#include "AST.hpp"

namespace IO::AST_log
{
    void printBlock(AST::Block *block)
    {
        IO::Logger::ast("\"Block\": {\n");
        IO::Logger::ast("\"lines\": {\n");
        size_t i = 0;
        for (AST::IExpr *e : block->getLines()) {
            IO::Logger::ast("\"%d\": {\n", i++);
            printExpr(e);
            IO::Logger::ast("},\n");
        }
        IO::Logger::ast("},\n");
        IO::Logger::ast("},\n");
    }
} // namespace IO::AST_log
