#include "CPT/Grammar/SpecialChar.hpp"
#include "IO.hpp"
#include <iostream>

namespace CPT
{
    namespace Grammar
    {
        struct result *SpecialChar::parse(Packrat::Parser &p)
        {
            p.save();
            IO::Logger::cpt_debug("\"SpecialChar\": {\n");

            struct result *r = new struct result;
            char c = Packrat::character(p, this->c);

            if (c == '\0') {
                p.rollback();
                IO::Logger::cpt_debug("\"message\": \"no special character detected\",\n");
                IO::Logger::cpt_debug("\"end\": \"fail\"}\n");
                return nullptr;
            }
            IO::Logger::cpt_debug("\"end\": \"success\"},\n");
            *r = {
                .exprs = {
                    new SpecialChar(c)
                }
            };
            return r;
        }
    } // namespace Grammar
} // namespace CPT
