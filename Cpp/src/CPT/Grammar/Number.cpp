#include "CPT/Grammar/Number.hpp"
#include "CPT/Packrat.hpp"
#include "IO.hpp"

namespace CPT
{
    namespace Grammar
    {
        Number::Number(int value) : value(value)
        {
        }

        struct result *Number::parse(Packrat::Parser &p)
        {
            IO::Logger::cpt_debug("\"Number\": {\n");
            p.save();

            struct result *res = new struct result;
            int *value = Packrat::number(p);

            if (value == nullptr) {
                IO::Logger::cpt_debug("\"end\": \"fail\",\n");
                IO::Logger::cpt_debug("\"reason\": \"Number is null\"},\n");
                p.rollback();
                return nullptr;
            }
            res->exprs = {};
            res->type = CPT_NUMBER;
            res->exprs.push_back(new Number(*value));
            p.commit();
            IO::Logger::cpt_debug("\"data\": %d,\n", *value);
            IO::Logger::cpt_debug("\"end\": \"success\"},\n");
            return res;
        }

        int Number::get()
        {
            return this->value;
        }
    }; // namespace Grammar
};     // namespace CPT
