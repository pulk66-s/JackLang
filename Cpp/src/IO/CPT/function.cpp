#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"
#include "CPT.hpp"

namespace IO::CPT_log {
    void printFnDecl(CPT::Grammar::FunctionDecl *fn)
    {
        Logger::cpt("\"FunctionDecl\": {\n");
        Logger::cpt("\"type\": \"%s\",\n", fn->get_type()->get().c_str());
        Logger::cpt("\"identifier\": \"%s\",\n", fn->get_identifier()->get().c_str());
        Logger::cpt("\"lines\": [\n");
        size_t i = 0;
        for (CPT::Packrat::IExpr *line : fn->get_lines()) {
            Logger::cpt("\"%d\": {\n", i++);
            printExpr(line);
            Logger::cpt("},\n");
        }
        Logger::cpt("],\n");
        Logger::cpt("},\n");
    }
}
