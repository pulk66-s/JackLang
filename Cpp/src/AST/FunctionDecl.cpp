#include "AST/FunctionDecl.hpp"
#include "AST/Block.hpp"
#include "IO.hpp"

namespace AST
{
    FunctionDecl::FunctionDecl(CPT::Grammar::FunctionDecl *fndecl)
    {
        IO::Logger::ast_debug("\"FunctionDecl\": {\n");
        this->name = fndecl->get_identifier()->get();
        this->blocks.push_back(new Block(fndecl->get_lines()));
        IO::Logger::ast_debug("\"end\": \"success\"},\n");
    }
} // namespace AST
