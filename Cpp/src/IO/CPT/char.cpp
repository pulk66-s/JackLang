#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"

namespace IO
{
    namespace CPT_log
    {
        void printChar(CPT::Grammar::SpecialChar *c)
        {
            Logger::cpt("\"char\": \"%c\",\n", c->get());
        }
    } // namespace CPT_log
    
} // namespace IO
