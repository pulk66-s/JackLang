#include "AST/Type.hpp"
#include "AST/Constant.hpp"
#include "AST/VarDecl.hpp"
#include "IO.hpp"

namespace AST
{
    VarDecl::VarDecl(CPT::Grammar::VariableDecl *vardecl)
    {
        IO::Logger::ast_debug("\"VarDecl\": {\n");
        this->name = vardecl->get();
        this->t = IType::createType(vardecl->getType());
        this->value = createValue(vardecl->getValue());
        if (!this->value) {
            IO::Logger::ast_debug("\"message\": \"Value is null\",\n");
            IO::Logger::ast_debug("\"end\": \"failure\"},\n");
            return;
        }
        if(!this->t) {
            IO::Logger::ast_debug("\"message\": \"Type is null\"");
            IO::Logger::ast_debug("\"end\": \"failure\"},\n");
            return;
        }
        IO::Logger::ast_debug("\"name\": \"%s\",\n", this->name.c_str());
        IO::Logger::ast_debug("\"end\": \"success\"},\n");
    }
} // namespace AST
