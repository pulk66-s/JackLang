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
        switch (vardecl->getValue()->type()) {
        case CPT::CPT_NUMBER:
            IO::Logger::ast_debug("\"message\": \"Number type\",\n");
            this->value = new Constant(((CPT::Grammar::Number *)vardecl->getValue())->get());
            IO::Logger::ast_debug("\"value\": \"%d\",\n", ((CPT::Grammar::Number *)vardecl->getValue())->get());
            break;
        default:
            IO::Logger::ast_debug("\"message\": \"Unknown type '%d'\",\n", vardecl->getValue()->type());
            break;
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
