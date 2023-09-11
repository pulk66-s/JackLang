#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"
#include "AST.hpp"

namespace IO::AST_log
{
    void printVarDecl(AST::VarDecl *var)
    {
        IO::Logger::ast("\"VarDecl\": {\n");
        IO::Logger::ast("\"name\": \"%s\",\n", var->getName().c_str());
        IO::Logger::ast("\"type\": \"%s\",\n", var->getType()->getName().c_str());
        IO::Logger::ast("\"value\": {\n");
        printExprValue(var->getValue());
        IO::Logger::ast("},\n");
        IO::Logger::ast("},\n");
    }
} // namespace IO::AST_log
