#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat/Parser.hpp"
#include <iostream>

namespace CPT
{
    namespace Packrat
    {
        char character(Packrat::Parser &p, char c)
        {
            if (p.next() == c) {
                p.commit();
                return c;
            }
            p.prev();
            return '\0';
        }
    } // namespace Packrat
} // namespace CPT
