#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"
#include "CPT.hpp"

namespace IO
{
    namespace CPT_log
    {
        void printType(CPT::Grammar::Type *type)
        {
            Logger::cpt("\"type\": {\n");
            Logger::cpt("\"name\": \"%s\",\n", type->get().c_str());
            Logger::cpt("},\n");
        }
    } // namespace CPT_log
    
} // namespace IO
