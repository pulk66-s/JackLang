#include "IO/File.hpp"
#include <fstream>

namespace IO
{
    File::File(std::string path)
    {
        this->path = path;
    }

    std::string File::read()
    {
        std::ifstream file(this->path);
        std::string content((std::istreambuf_iterator<char>(file)),
                            (std::istreambuf_iterator<char>()));
        return content;
    }

    void File::write(std::string content)
    {
        std::ofstream file(this->path);
        file << content;
        file.close();
    }
} // namespace IO
