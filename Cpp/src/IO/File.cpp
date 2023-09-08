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

    void File::write_vargs(std::string fmt, va_list args)
    {
        char *buffer;
        vasprintf(&buffer, fmt.c_str(), args);
        this->write(buffer);
        free(buffer);
    }

    void File::append(std::string content)
    {
        std::ofstream file(this->path, std::ios_base::app);
        file << content;
        file.close();
    }

    void File::append_vargs(std::string fmt, va_list args)
    {
        char *buffer;
        vasprintf(&buffer, fmt.c_str(), args);
        this->append(buffer);
        free(buffer);
    }

    void File::del()
    {
        remove(this->path.c_str());
    }
} // namespace IO
