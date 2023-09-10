#include "AST/Block.hpp"
#include "AST/VarDecl.hpp"
#include "IO.hpp"

namespace AST
{
    Block::Block(std::vector<CPT::Packrat::IExpr *> lines)
    {
        IO::Logger::ast_debug("\"Block\": {\n");
        size_t i = 0;
        for (CPT::Packrat::IExpr *line : lines) {
            IO::Logger::ast_debug("\"message\": \"Line %d\",\n", i++);
            switch (line->type()) {
            case CPT::CPT_VARDECL:
                IO::Logger::ast_debug("\"message\": \"VarDecl\",\n");
                this->lines.push_back(new VarDecl((CPT::Grammar::VariableDecl *)line));
                break;
            default:
                IO::Logger::ast_debug("\"message\": \"Unknown line type %d\",\n", line->type());
                break;
            }
        }
        IO::Logger::ast_debug("\"end\": \"success\"},\n");
    }
} // namespace AST
