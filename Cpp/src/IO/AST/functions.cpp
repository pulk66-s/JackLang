#include "AST.hpp"
#include "IO/Logger.hpp"

namespace IO::AST_log
{
    void printFnDecl(AST::FunctionDecl *fn)
    {
        IO::Logger::ast("\"FunctionDecl\": {\n");
        IO::Logger::ast("\"name\": \"%s\",\n", fn->getName().c_str());
        IO::Logger::ast("\"Blocks\": {\n");
        size_t i = 0;
        for (AST::Block *b : fn->getBlocks()) {
            IO::Logger::ast("\"%d\": {\n", i++);
            printBlock(b);
            IO::Logger::ast("},\n");
        }
        IO::Logger::ast("},\n");
        IO::Logger::ast("},\n");
    }
} // namespace IO::AST_log
