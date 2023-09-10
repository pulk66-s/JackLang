#ifndef __CL_IO_LOGGER_HPP__
#define __CL_IO_LOGGER_HPP__

#include "IO/IONamespace.hpp"
#include <string>

namespace IO
{
    class Logger
    {
    public:
        enum Type {
            CONSOLE     = 1 << 0,
            DEBUG       = 1 << 1,
            CPT         = 1 << 2,
            CPT_DEBUG   = 1 << 3,
            AST         = 1 << 4,
            AST_DEBUG   = 1 << 5,
        };

        static bool hasType(int type);
        static void setType(int type);
        static void unsetType(int type);

        static void console(std::string fmt, ...);
        static void debug(std::string fmt, ...);
        static void cpt(std::string fmt, ...);
        static void cpt_debug(std::string fmt, ...);
        static void ast(std::string fmt, ...);
        static void ast_debug(std::string fmt, ...);
    };
} // namespace IO

#endif
