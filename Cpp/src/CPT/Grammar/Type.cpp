#include "CPT/Grammar/Type.hpp"
#include "IO.hpp"

namespace CPT
{
    namespace Grammar
    {
        struct result *Type::parse(Packrat::Parser &p)
        {
            p.save();
            IO::Logger::cpt_debug("\"Type\": {\n");

            struct result *r = new struct result;
            std::string word = Packrat::word(p);

            if (word == "") {
                p.rollback();
                IO::Logger::cpt_debug("\"message\": \"no type detected\",\n");
                IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
                return nullptr;
            }
            IO::Logger::cpt_debug("\"type\": \"%s\",\n", word.c_str());
            IO::Logger::cpt_debug("\"end\": \"success\"},\n");
            *r = {
                .exprs = {
                    new Type(word)
                }
            };
            p.commit();
            return r;
        }
    } // namespace Grammar
} // namespace CPT
