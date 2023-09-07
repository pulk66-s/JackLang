#include "IO.hpp"
#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat.hpp"
#include <iostream>

namespace CPT
{
    namespace Packrat
    {
        int *number(CPT::Packrat::Parser &p)
        {
            int *res = nullptr;

            for (char c = p.next(); c >= '0' && c <= '9'; c = p.next()) {
                if (res == nullptr) {
                    res = new int(0);
                }
                *res = *res * 10 + (c - '0');
            }
            p.prev();
            return res;
        }
    } // namespace Packrat
} // namespace CPT
