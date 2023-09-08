#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"

namespace IO
{
    namespace CPT_log
    {
        void printIdentifier(CPT::Grammar::Identifier *id)
        {
            Logger::cpt("\"identifier\": {\n");
            Logger::cpt("\"name\": \"%s\",\n", id->get().c_str());
            Logger::cpt("},\n");
        }
    } // namespace CPT_log
} // namespace IO
