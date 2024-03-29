#include "Parser/Token.hpp"
#include <sstream>
#include <iostream>

std::vector<std::string> Tokenizer::createLines(std::string content)
{
    std::vector<std::string> lines;
    std::string line;
    std::istringstream stream(content);

    while (std::getline(stream, line)) {
        lines.push_back(line);
    }

    return lines;
}

std::vector<std::string> Tokenizer::createTokens(std::string line)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream stream(line);

    while (std::getline(stream, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<std::vector<std::string>> Tokenizer::tokenize(std::string filePath)
{
    IO::Logger::console("Tokenizing file %s\n", filePath.c_str());
    IO::File file(filePath);
    std::string content = file.read();
    std::vector<std::string> lines = this->createLines(content);
    std::vector<std::vector<std::string>> tokens = {};

    for (std::string line : lines) {
        tokens.push_back(this->createTokens(line));
    }
    for (std::vector<std::string> &line : tokens) {
        std::vector<std::string> res = {};
        std::copy_if(line.begin(), line.end(), std::back_inserter(res), [](std::string token) {
            return !token.empty();
        });
        line = res;
    }
    for (std::vector<std::string> line : tokens) {
        for (std::string token : line) {
            IO::Logger::console("%s ", token.c_str());
        }
        IO::Logger::console("\n");
    }
    return tokens;
}
