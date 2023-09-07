#include "CPT/Grammar/Program.hpp"
#include "CPT/Grammar/Number.hpp"
#include "IO.hpp"

namespace CPT
{
    namespace Grammar
    {
        struct result *Program::parse(Packrat::Parser &p)
        {
            p.save();
            IO::Logger::cpt_debug("\"Program\": {\n");

            struct result *res = Number::parse(p);

            if (!res) {
                IO::Logger::cpt_debug("\"message\": \"result is null\",\n");
                IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            }
            IO::Logger::cpt_debug("\"end\": \"success\"},\n");
            return res;
        }
    } // namespace Grammar
    
} // namespace CPT
