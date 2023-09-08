#include "IO/Logger.hpp"
#include "IO/File.hpp"
#include <cstdarg>
#include <string>
#include <iostream>

static int logType =    IO::Logger::Type::CONSOLE |
                        IO::Logger::Type::DEBUG |
                        IO::Logger::Type::CPT |
                        IO::Logger::Type::CPT_DEBUG;

static std::string RED = "\033[0;31m";
static std::string GREEN = "\033[0;32m";
static std::string YELLOW = "\033[0;33m";
static std::string BLUE = "\033[0;34m";
static std::string MAGENTA = "\033[0;35m";
static std::string NC = "\033[0m";

namespace IO
{
    bool Logger::hasType(int type)
    {
        return logType & type;
    }

    void Logger::setType(int type)
    {
        logType |= type;
    }

    void Logger::unsetType(int type)
    {
        logType &= ~type;
    }

    void Logger::console(std::string fmt, ...)
    {
        if (Logger::hasType(Logger::Type::CONSOLE)) {
            va_list args;
            va_start(args, fmt);
            std::cout << GREEN << "[CONSOLE] " << NC;
            vprintf(fmt.c_str(), args);
            va_end(args);
        }
    }

    void Logger::debug(std::string fmt, ...)
    {
        if (Logger::hasType(Logger::Type::DEBUG)) {
            va_list args;
            va_start(args, fmt);
            std::cout << BLUE << "[DEBUG] " << NC;
            vprintf(fmt.c_str(), args);
            va_end(args);
        }
    }

    void Logger::cpt(std::string fmt, ...)
    {
        if (Logger::hasType(Logger::Type::CPT)) {
            File f("log/cpt.json");
            va_list args, copy;
            va_start(args, fmt);
            va_copy(copy, args);
            std::cout << YELLOW << "[CPT] " << NC;
            vprintf(fmt.c_str(), args);
            f.append_vargs(fmt, copy);
            va_end(args);
        }
    }

    void Logger::cpt_debug(std::string fmt, ...)
    {
        if (Logger::hasType(Logger::Type::CPT_DEBUG)) {
            File f("log/cpt.log");
            va_list args, copy;
            va_start(args, fmt);
            va_copy(copy, args);
            std::cout << MAGENTA << "[CPT_DEBUG] " << NC;
            vprintf(fmt.c_str(), args);
            f.append_vargs(fmt, copy);
            va_end(args);
        }
    }
} // namespace IO
