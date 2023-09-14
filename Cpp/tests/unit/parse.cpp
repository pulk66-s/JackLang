#include "parse.hpp"
#include "Parser/Token.hpp"
#include <iostream>

struct CPT::result *parse_file(std::string path, std::function<struct CPT::result *(CPT::Packrat::Parser &)> f) {
    Tokenizer t;
    std::vector<std::vector<std::string>> tokens = t.tokenize(path);
    CPT::Packrat::Parser p(tokens);
    CPT::Grammar::Program program;
    struct CPT::result *r = program.parse(p, f);

    return r;
}
