#include "CPT/Grammar/Function/FunctionDecl.hpp"
#include "CPT/Grammar/Function/FunctionLines.hpp"
#include "CPT/Grammar/SpecialChar.hpp"
#include "CPT/CPTNamespace.hpp"
#include "IO.hpp"

namespace CPT::Grammar {
    struct result *FunctionDecl::parse(CPT::Packrat::Parser &p)
    {
        p.save();
        IO::Logger::cpt_debug("\"FunctionDecl\": {\n");
        
        struct result *res = sequence(p, {
            new Type(),
            new Identifier(),
            new SpecialChar('('),
            new SpecialChar(')'),
            new SpecialChar('{'),
            new FunctionLines(),
            new SpecialChar('}'),
        });
        struct result *ret = new struct result;
        if (!res) {
            p.rollback();
            IO::Logger::cpt_debug("\"message\": \"Sequence is null\",\n");
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            return nullptr;
        }
        Type *t = (Type *)res->exprs[0];
        Identifier *identifier = (Identifier *)res->exprs[1];
        FunctionLines *lines = (FunctionLines *)res->exprs[5];

        ret->exprs = { new FunctionDecl(t, identifier, lines->get_lines()) };
        for (Packrat::IExpr *line : lines->get_lines()) {
            IO::Logger::cpt_debug("\"line\": %d\n", line->type());
        }
        IO::Logger::cpt_debug("\"type\": \"%s\",\n", t->get().c_str());
        IO::Logger::cpt_debug("\"identifier\": \"%s\",\n", identifier->get().c_str());
        IO::Logger::cpt_debug("\"nb_lines\": %d,\n", lines->get_lines().size());
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        p.commit();
        return ret;
    }
}
