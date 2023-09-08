#include "CPT/CPTNamespace.hpp"
#include "IO.hpp"
#include "CPT/Packrat/Expr.hpp"

namespace CPT
{
    namespace Packrat
    {
        struct result *sequence(Parser &p, std::vector<IExpr *> exprs)
        {
            IO::Logger::cpt_debug("\"sequence\": {\n");

            struct result *r = new struct result;
            int index = 0;

            r->exprs = {};
            for (auto expr : exprs) {
                struct result *r2 = expr->parse(p);
                if (r2 == nullptr) {
                    IO::Logger::cpt_debug("\"end\": \"fail expr %d\"},\n", index);
                    return nullptr;
                }
                IO::Logger::cpt_debug("\"expr %d\": \"success\",\n", index++);
                r->exprs.insert(r->exprs.end(), r2->exprs.begin(), r2->exprs.end());
            }
            IO::Logger::cpt_debug("\"end\": \"success\"},\n");
            return r;
        }
    } // namespace Packrat
    
} // namespace CPT
