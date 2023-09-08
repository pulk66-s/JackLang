#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"

namespace IO
{
    namespace CPT_log
    {
        void printVar(CPT::Grammar::Variable *var)
        {
            Logger::cpt("\"variable\": {\n");
            Logger::cpt("\"name\": \"%s\",\n", var->get().c_str());
            Logger::cpt("\"type\": \"%s\",\n", var->getType()->get().c_str());
            Logger::cpt("\"value\": {\n");
            printExpr(var->getValue());
            Logger::cpt("},\n");
            Logger::cpt("},\n");
        }
    } // namespace CPT_log
} // namespace IO
