#include "CPT/Grammar/Keyword/AKeyword.hpp"
#include "IO.hpp"

namespace CPT::Grammar::Keyword
{
    struct result *AKeyword::parse(Packrat::Parser &p) {
        IO::Logger::cpt_debug("\"%s\": {\n", this->data.c_str());
        p.save();
        std::string s = Packrat::keyword(p, this->data);
        if (s == "") {
            IO::Logger::cpt_debug("\"message\": \"Failed to parse %s keyword\",\n", this->data.c_str());
            IO::Logger::cpt_debug("\"end\": \"fail\"},\n");
            p.rollback();
            this->data = "";
            return nullptr;
        }
        struct result *res = new struct result;
        res->exprs = {new Keyword::AKeyword(this->data)};
        p.commit();
        IO::Logger::cpt_debug("\"message\": \"Parsed If keyword\",\n");
        IO::Logger::cpt_debug("\"end\": \"success\"},\n");
        return res;
    };
} // namespace CPT::Grammar::Keyword
