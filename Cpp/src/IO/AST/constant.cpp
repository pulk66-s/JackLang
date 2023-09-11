#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"
#include "AST.hpp"

namespace IO::AST_log
{
    void printConstant(AST::Constant *c)
    {
        IO::Logger::ast("\"Constant\": {\n");
        IO::Logger::ast("\"value\": %d,\n", c->getValue());
        IO::Logger::ast("},\n");
    }
} // namespace IO::AST_log
