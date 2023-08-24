#include "grammar/word.h"
#include "grammar/default.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

static inline bool is_alpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

struct result word(struct packrat *p)
{
    if (!p->content[p->y] || !p->content[p->y][p->x]) {
        return FAIL_RESULT;
    }

    char *buf = NULL;
    size_t cursor_index = p->cursor;
    size_t x = p->x;
    size_t y = p->y;
    size_t size = 0;

    while (true) {
        if (is_alpha(next(p))) {
            size++;
        } else {
            prev(p);
            break;
        }
    }
    if (!size) {
        return FAIL_RESULT;
    }
    buf = malloc(sizeof(char) * (size + 1));
    memset(buf, 0, sizeof(char) * (size + 1));
    strncpy(buf, &p->content[y][x][cursor_index], size);
    return (struct result) {
        .size = 1,
        .success = true,
        .data = buf,
        .datatype = STRING
    };
}

struct result number(struct packrat *p)
{
    if (!p->content[p->y] || !p->content[p->y][p->x]) {
        return FAIL_RESULT;
    }

    const char *word = &p->content[p->y][p->x][p->cursor];
    struct result res = DEFAULT_RESULT;
    size_t letter_index = 0;
    int *nb = malloc(sizeof(int));

    for (size_t i = 0; word[i]; i++) {
        if (word[i] >= '0' && word[i] <= '9') {
            letter_index++;
        } else {
            break;
        }
    }
    if (!letter_index) {
        return FAIL_RESULT;
    }
    *nb = atoi(word);
    res = (struct result) {
        .size = 1,
        .success = true,
        .data = nb,
        .datatype = NUMBER
    };
    for (size_t i = 0; i < letter_index; i++) {
        next(p);
    }
    return res;
}