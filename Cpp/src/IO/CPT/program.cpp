#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"
#include "CPT.hpp"

namespace IO
{
    namespace CPT_log
    {
        void printPrgm(CPT::Grammar::Program *prgm)
        {
            Logger::cpt("\"program\": {\n");
            std::vector<CPT::Packrat::IExpr *> exprs = prgm->get();

            Logger::cpt("\"exprs\": [\n");
            for (CPT::Packrat::IExpr *e : exprs) {
                Logger::cpt("{\n");
                printExpr(e);
                Logger::cpt("},\n");
            }
            Logger::cpt("],\n");
            Logger::cpt("},\n");
        }
    } // namespace CPT_log
} // namespace IO

