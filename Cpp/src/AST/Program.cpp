#include "AST/Program.hpp"
#include "IO.hpp"

namespace AST
{
    Program::Program(CPT::Grammar::Program *prgm)
    {
        IO::Logger::ast_debug("\"Program\": {\n");
        for (CPT::Packrat::IExpr *e : prgm->get()) {
            switch (e->type()) {
            case CPT::CPT_FN_DECL:
                IO::Logger::ast_debug("\"message\": \"FunctionDecl\",\n");
                this->functions.push_back(new FunctionDecl((CPT::Grammar::FunctionDecl *)e));
                break;
            default:
                IO::Logger::ast_debug("\"message\": \"Unknown e %d\",\n", e->type());
                break;
            }
        }
        IO::Logger::ast_debug("\"end\": \"success\"},\n");
    }
} // namespace AST
