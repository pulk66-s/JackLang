#include "CPT/Packrat/Parser.hpp"
#include "IO.hpp"

namespace CPT
{
    namespace Packrat
    {
        Parser::Parser(std::vector<std::vector<std::string>> const &tokens)
            : tokens(tokens), p({0, 0, 0})
        {
        }

        struct pos Parser::getPos() const
        {
            return this->p;
        }

        char Parser::next()
        {
            if (this->p.y >= this->tokens.size()) {
                return 0;
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
            if (this->p.x == 0)
            {
                this->p.x = this->tokens[this->p.y].size();
                this->p.y--;
                if (this->p.y == 0)
                {
                    this->p.y = this->tokens.size();
                    this->p.z--;
                    if (this->p.z == 0)
                    {
                        this->p.z = this->tokens[0].size();
                    }
                }
            }
            this->p.x--;
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
    }; // namespace Packrat
};     // namespace CPT