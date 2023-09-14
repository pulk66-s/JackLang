#include "CPT/Grammar/Program.hpp"
#include "CPT/Grammar/Number.hpp"
#include "CPT/Grammar/Function.hpp"
#include "CPT/Packrat.hpp"
#include "IO.hpp"

namespace CPT::Grammar
{
    struct result *Program::parse(Packrat::Parser &p)
    {
        return this->parse(p, [&](Packrat::Parser &p) -> struct result * {
            return zero_or_more(p, new FunctionDecl());
        });
    }

    struct result *Program::parse(Packrat::Parser &p, std::function<struct result *(Packrat::Parser &)> f)
    {
        p.save();
        IO::Logger::cpt_debug("\"Program\": {\n");

        struct result *var_res = f(p);
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
} // namespace CPT
