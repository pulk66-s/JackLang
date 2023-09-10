#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"

namespace IO::CPT_log
{
    void printCond(CPT::Grammar::Condition *cond)
    {
        Logger::cpt("\"Condition\": {\n");
        Logger::cpt("\"cond\": {\n");
        if (cond->getCond()) {
            printExpr(cond->getCond());
        }
        Logger::cpt("},\n");
        Logger::cpt("\"then\": [\n");
        size_t i = 0;
        for (CPT::Packrat::IExpr *line : cond->getIfTrue()) {
            Logger::cpt("\"%d\": {\n", i++);
            printExpr(line);
            Logger::cpt("},\n");
        }
        Logger::cpt("],\n");
        Logger::cpt("\"else\": [\n");
        i = 0;
        for (CPT::Packrat::IExpr *line : cond->getIfFalse()) {
            Logger::cpt("\"%d\": {\n", i++);
            printExpr(line);
            Logger::cpt("},\n");
        }
        Logger::cpt("],\n");
        Logger::cpt("},\n");
    }
} // namespace IO::CPT_log
