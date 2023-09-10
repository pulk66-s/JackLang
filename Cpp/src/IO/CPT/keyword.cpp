#include "IO/IONamespace.hpp"
#include "IO/Logger.hpp"
#include "CPT.hpp"

namespace IO::CPT_log
{
    void printKeyword(CPT::Grammar::Keyword::AKeyword *kw)
    {
        Logger::cpt("\"keyword\": \"%s\"", kw->get().c_str());
    }
} // namespace IO::CPT_log
