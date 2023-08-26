#include "parsing/default/char.h"

inline char next(struct parsing *p)
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
