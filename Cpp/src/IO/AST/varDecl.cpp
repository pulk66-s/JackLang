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
        switch (var->getValue()->type()) {
            case AST::AST_CONSTANT:
                printConstant((AST::Constant *)var->getValue());
                break;
            default:
                IO::Logger::ast("\"message\": \"Unknown type '%d'\",\n", var->getValue()->type());
                break;
        }
        IO::Logger::ast("},\n");
        IO::Logger::ast("},\n");
    }
} // namespace IO::AST_log
