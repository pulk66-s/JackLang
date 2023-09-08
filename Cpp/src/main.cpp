#include <iostream>
#include <llvm/IR/IRBuilder.h>
#include "IO.hpp"
#include "Parser/Token.hpp"
#include "CPT.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return 1;

    IO::File("log/cpt.log").del();
    IO::File("log/cpt.json").del();

    Tokenizer tokenizer;
    std::vector<std::vector<std::string>> tokens = tokenizer.tokenize(av[1]);

    for (std::vector<std::string> line : tokens) {
        for (std::string token : line) {
            std::cout << "(" << token << ") ";
        }
        std::cout << std::endl;
    }
    CPT::Packrat::Parser parser(tokens);
    struct CPT::result *res = CPT::Grammar::Program().parse(parser);

    if (!res) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    IO::CPT_log::printExprs(res->exprs);
    return 0;
}
