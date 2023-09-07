#ifndef __CL_PARSER_TOKEN_HPP__
#define __CL_PARSER_TOKEN_HPP__

#include "IO.hpp"
#include <vector>

class Tokenizer {
public:
    std::vector<std::vector<std::string>> tokenize(std::string filePath);

private:
    std::vector<std::string> createLines(std::string content);
    std::vector<std::string> createTokens(std::string line);
};

#endif
