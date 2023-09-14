/**
 * Identifier Grammar Sources
 * See the Documentation (doc/code/Grammar/Identifier.md)
*/

#include "CPT/Grammar/Identifier.hpp"
#include "IO.hpp"

namespace CPT::Grammar
{
    struct result *Identifier::parse(Packrat::Parser &p)
    {
        p.save();
        IO::Logger::cpt_debug("\"Identifier\": {\n");

        struct result *r = new struct result;
        std::string word = Packrat::identifier(p);

        if (word == "") {
            p.rollback();
            IO::Logger::cpt_debug("\"message\": \"no identifier detected\",\n");
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            return nullptr;
        }
        *r = {
            .exprs = {
                new Identifier(word)
            }
        };
        IO::Logger::cpt_debug("\"identifier\": \"%s\",\n", word.c_str());
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        return r;
    }
} // namespace CPT
