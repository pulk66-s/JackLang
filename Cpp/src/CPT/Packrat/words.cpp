#include "CPT/CPTNamespace.hpp"
#include "CPT/Packrat/Parser.hpp"
#include "IO.hpp"
#include <iostream>

namespace CPT
{
    namespace Packrat
    {
        bool isNextWord(struct Packrat::pos prev, struct Packrat::pos now)
        {
            return !(prev.y == now.y && prev.x == now.x);
        }

        bool isAlpha(char c)
        {
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        }

        bool isDigit(char c)
        {
            return c >= '0' && c <= '9';
        }

        bool isAlphaNum(char c)
        {
            return isAlpha(c) || isDigit(c);
        }

        std::string word(Packrat::Parser &p)
        {
            struct Packrat::pos prev = p.getPos();
            std::string s = "";

            for (char c = p.next(); isAlpha(c) && !isNextWord(prev, p.getPos()); c = p.next()) {
                s += c;
            }
            p.prev();
            return s;
        }

        std::string identifier(Packrat::Parser &p)
        {
            struct Packrat::pos prev = p.getPos();
            std::string s = "";
            char c = p.next();

            if (!isAlpha(c)) {
                p.prev();
                return "";
            }
            s += c;
            for (c = p.next(); (isAlphaNum(c) || c == '_') && !isNextWord(prev, p.getPos()); c = p.next()) {
                s += c;
            }
            p.prev();
            return s;
        }

        std::string keyword(Packrat::Parser &p, std::string word)
        {
            std::string s = "";

            p.save();
            for (char c : word) {
                if (p.next() != c) {
                    p.rollback();
                    return "";
                }
            }
            p.commit();
            return word;
        }
    } // namespace Grammar
    
} // namespace CPT
