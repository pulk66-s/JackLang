#include "CPT/Packrat/Parser.hpp"
#include "Parser/Token.hpp"
#include "IO.hpp"
#include <iostream>

namespace CPT::Packrat
{
    Parser::Parser(std::vector<std::vector<std::string>> const &tokens)
        : tokens(tokens), p({0, 0, 0})
    {
        for (std::vector<std::string> line : this->tokens) {
            for (std::string token : line) {
                std::cout << "(" << token << ") ";
            }
            std::cout << std::endl;
        }
    }

    struct pos Parser::getPos() const
    {
        return this->p;
    }

    char Parser::next()
    {
        if (this->p.y >= this->tokens.size()) {
            return '\0';
        }
        if (this->p.x >= this->tokens[this->p.y].size()) {
            this->p.y++;
            this->p.x = 0;
            return this->next();
        }
        if (this->p.z >= this->tokens[this->p.y][this->p.x].size()) {
            this->p.x++;
            this->p.z = 0;
            return this->next();
        }
        return this->tokens[this->p.y][this->p.x][this->p.z++];
    }

    void Parser::prev()
    {
        if (this->p.z == 0) {
            if (this->p.x == 0) {
                if (this->p.y == 0) {
                    return;
                }
                this->p.y--;
                this->p.x = this->tokens[this->p.y].size() - 1;
                this->p.z = this->tokens[this->p.y][this->p.x].size() - 1;
            } else {
                this->p.x--;
                this->p.z = this->tokens[this->p.y][this->p.x].size() - 1;
            }
        } else {
            this->p.z--;
        }
    }

    void Parser::save()
    {
        this->saves.push_back(this->p);
    }

    void Parser::rollback()
    {
        this->p = this->saves.back();
        this->saves.pop_back();
    }

    void Parser::commit()
    {
        this->saves.pop_back();
    }

    char Parser::get()
    {
        return this->tokens[this->p.y][this->p.x][this->p.z];
    }
};     // namespace CPT
