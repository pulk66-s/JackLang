#include "IO/Logger.hpp"
#include "AST.hpp"

namespace IO::AST_log
{
    void printPrgm(AST::Program *prgm)
    {
        IO::Logger::ast("\"Program\": {\n");
        IO::Logger::ast("\"Functions\": {\n");
        size_t i = 0;
        for (AST::FunctionDecl *fn : prgm->getFunctions()) {
            IO::Logger::ast("\"%d\": {\n", i++);
            printFnDecl(fn);
            IO::Logger::ast("},\n");
        }
        IO::Logger::ast("},\n");
        IO::Logger::ast("},\n");
    }
} // namespace IO::AST_log
