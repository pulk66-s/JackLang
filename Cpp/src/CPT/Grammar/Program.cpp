#include "CPT/Grammar/Program.hpp"
#include "CPT/Grammar/Number.hpp"
#include "CPT/Grammar/Function.hpp"
#include "IO.hpp"

namespace CPT
{
    namespace Grammar
    {
        struct result *Program::parse(Packrat::Parser &p)
        {
            p.save();
            IO::Logger::cpt_debug("\"Program\": {\n");

            struct result *var_res = FunctionDecl().parse(p);
            struct result *res = new struct result;

            if (!var_res) {
                IO::Logger::cpt_debug("\"message\": \"result is null\",\n");
                IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
                return nullptr;
            }
            res->exprs.push_back(new Program(var_res->exprs));
            IO::Logger::cpt_debug("\"end\": \"success\"},\n");
            return res;
        }
    } // namespace Grammar
    
} // namespace CPT
