#include "parsing/default/char.h"

/**
 * @brief       Get the next character of the program
 * @param   p   The parsing structure
 * @return      The next character of the program (0 if the end of the program is reached)
*/
inline char next(struct parser *p)
{
    if (!p->tokens[p->pos.y]) {
        return 0;
    }
    if (!p->tokens[p->pos.y][p->pos.x]) {
        p->pos.y++;
        p->pos.x = 0;
        return next(p);
    }
    if (!p->tokens[p->pos.y][p->pos.x][p->pos.cursor]) {
        p->pos.x++;
        p->pos.cursor = 0;
        return next(p);
    }
    return p->tokens[p->pos.y][p->pos.x][p->pos.cursor++];
}

/**
 * @brief       Save the current position of the parser
 * @param   p   The parsing structure
*/
void save(struct parser *p)
{
    struct save_pos *save = malloc(sizeof(struct save_pos));

    save->pos = p->pos;
    save->next = p->save_pos;
    p->save_pos = save;
}

/**
 * @brief       Restore the last saved position of the parser
*/
void rollback(struct parser *p)
{
    struct save_pos *save = p->save_pos;

    p->pos = save->pos;
    p->save_pos = save->next;
    free(save);
}
