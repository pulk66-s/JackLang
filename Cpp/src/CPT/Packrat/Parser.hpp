#ifndef __CL_CPT_PACKRAT_PARSER_HPP__
#define __CL_CPT_PACKRAT_PARSER_HPP__

#include "CPT/CPTNamespace.hpp"
#include <cstddef>
#include <vector>
#include <string>

namespace CPT
{
    namespace Packrat
    {
        struct pos {
            size_t x, y, z;
        };

        class Parser
        {
        public:
            Parser(std::vector<std::vector<std::string>> const &tokens);
            struct pos getPos() const;
            char next();
            void prev();
            void save();
            void rollback();
            void commit();

        private:
            std::vector<std::vector<std::string>> const &tokens;
            struct pos p;
            std::vector<struct pos> saves;
        };
    }; // namespace Packrat
};     // namespace CPT

#endif
