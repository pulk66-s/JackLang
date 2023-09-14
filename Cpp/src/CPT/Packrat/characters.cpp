#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat/Parser.hpp"
#include <iostream>
#include "IO.hpp"

namespace CPT::Packrat
{
    char character(Packrat::Parser &p, char c)
    {
        char target = p.next();
        if (target == c) {
            p.commit();
            return c;
        }
        IO::Logger::cpt_debug("\"character char\": \"%c != %c\",\n", target, c);
        p.prev();
        return '\0';
    }
} // namespace CPT
