#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"

namespace IO
{
    namespace CPT_log
    {
        void printNb(CPT::Grammar::Number *nb)
        {
            Logger::cpt("\"number\": %d,\n", nb->get());
        }
    } // namespace CPT_log
} // namespace IO
