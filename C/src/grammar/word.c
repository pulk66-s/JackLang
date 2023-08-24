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

    const char *buf = &p->content[p->y][p->x][p->cursor];
    size_t size = 0;

    for (; buf[size] && is_alpha(buf[size]); size++);
    if (!size) {
        return FAIL_RESULT;
    }
    for (size_t i = 0; i < size; i++) {
        next(p);
    }
    return (struct result) {
        .size = 1,
        .success = true,
        .data = strndup(buf, size),
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