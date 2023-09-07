#ifndef __CL_IO_FILE_HPP__
#define __CL_IO_FILE_HPP__

#include "IO/IONamespace.hpp"
#include <string>

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
    };
} // namespace IO

#endif
