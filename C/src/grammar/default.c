#include "grammar/default.h"
#include <stdlib.h>

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

struct result zero_or_more(struct packrat *p, expr_t e)
{
    struct result res = {.success = true, .data = NULL};
    size_t nb_success = 0;

    while (true) {
        struct result r = e(p);
        if (!r.success) {
            break;
        }
        nb_success++;
        if (!res.data) {
            res.data = malloc(sizeof(struct result));
        } else {
            res.data = realloc(res.data, sizeof(struct result) * nb_success);
        }
        ((struct result *) res.data)[nb_success - 1] = r;
    }
    res.size = nb_success;
    return res;
}
