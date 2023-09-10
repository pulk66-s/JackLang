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

        struct result *zero_or_more(Parser &p, IExpr *expr)
        {
            IO::Logger::cpt_debug("\"zero_or_more\": {\n");

            struct result *r = new struct result;
            size_t index = 0;

            r->exprs = {};
            while (true) {
                struct result *r2 = expr->parse(p);
                if (r2 == nullptr) {
                    IO::Logger::cpt_debug("\"expr %d\": \"fail\",\n", index);
                    break;
                }
                IO::Logger::cpt_debug("\"expr %d\": \"success\",\n", index++);
                r->exprs.insert(r->exprs.end(), r2->exprs.begin(), r2->exprs.end());
            }
            IO::Logger::cpt_debug("\"end\": \"success\"},\n");
            return r;
        }

        struct result *ordered_choice(Parser &p, std::vector<IExpr *> exprs)
        {
            IO::Logger::cpt_debug("\"ordered_choice\": {\n");

            struct result *r = new struct result;
            int index = 0;

            r->exprs = {};
            for (auto expr : exprs) {
                struct result *r2 = expr->parse(p);
                if (r2 != nullptr) {
                    r->exprs.insert(r->exprs.end(), r2->exprs.begin(), r2->exprs.end());
                    IO::Logger::cpt_debug("\"expr %d\": \"success\"},\n", index);
                    return r;
                }
                IO::Logger::cpt_debug("\"expr %d\": \"fail\",\n", index++);
            }
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            return nullptr;
        }
    } // namespace Packrat
    
} // namespace CPT
