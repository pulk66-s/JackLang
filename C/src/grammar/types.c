#include "grammar/types.h"

inline char next(struct packrat *p)
{
    if (!p->content[p->y]) {
        return '\0';
    }

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

inline void prev(struct packrat *p)
{
    if (p->cursor == 0) {
        if (p->x == 0) {
            p->y--;
            p->x = 0;
            while (p->content[p->y][p->x]) {
                p->x++;
            }
            p->x--;
            while (p->content[p->y][p->x][p->cursor]) {
                p->cursor++;
            }
            p->cursor--;
        } else {
            p->x--;
            while (p->content[p->y][p->x][p->cursor]) {
                p->cursor++;
            }
            p->cursor--;
        }
    } else {
        p->cursor--;
    }
}

inline void next_word(struct packrat *p)
{
    p->x++;
    if (!p->content[p->y][p->x]) {
        p->x = 0;
        p->y++;
    }
}
