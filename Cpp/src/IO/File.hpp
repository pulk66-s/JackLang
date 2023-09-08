#ifndef __CL_IO_FILE_HPP__
#define __CL_IO_FILE_HPP__

#include "IO/IONamespace.hpp"
#include <string>
#include <stdarg.h>

namespace IO
{
    class File
    {
    private:
        std::string path;

    public:
        File(std::string path);
        std::string read();
        void write(std::string content);
        void write_vargs(std::string fmt, va_list args);
        void append(std::string content);
        void append_vargs(std::string fmt, va_list args);
        void del();
    };
} // namespace IO

#endif
