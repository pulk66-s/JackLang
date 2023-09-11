#include "IO.hpp"
#include "CPT/Grammar/Statement.hpp"
#include "CPT/Grammar/VariableDecl.hpp"
#include "CPT/Grammar/SpecialChar.hpp"

namespace CPT::Grammar
{
    struct result *Statement::parse(Packrat::Parser &p)
    {
        p.save();
        IO::Logger::cpt_debug("\"Statement\": {\n");

        struct result *res = ordered_choice(p, {
            new VariableDecl(),
        });
        struct result *endline = SpecialChar(';').parse(p);

        if (!res) {
            p.rollback();
            IO::Logger::cpt_debug("\"message\": \"Choice is null\",\n");
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            return nullptr;
        }
        if (!endline) {
            p.rollback();
            IO::Logger::cpt_debug("\"message\": \"Endline is null\",\n");
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            return nullptr;
        }
        p.commit();
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        return res;
    }
} // namespace CPT::Grammar
