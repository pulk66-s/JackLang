#include "grammar/types.h"

inline char next(struct packrat *p)
{
    char c = p->content[p->y][p->x][p->cursor];
    char new_c = p->content[p->y][p->x][p->cursor + 1];

    if (new_c == '\0') {
        p->cursor = 0;
        p->x++;
        if (!p->content[p->y][p->x]) {
            p->x = 0;
            p->y++;
        }
    } else {
        p->cursor++;
    }
    return c;
}

inline void next_word(struct packrat *p)
{
    p->x++;
    if (!p->content[p->y][p->x]) {
        p->x = 0;
        p->y++;
    }
}
