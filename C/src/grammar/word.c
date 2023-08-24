#include "grammar/word.h"
#include "grammar/default.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static inline bool is_alpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

struct result word(struct packrat *p)
{
    if (!p->content[p->y] || !p->content[p->y][p->x]) {
        return (struct result) {
            .success = false,
            .size = 0,
            .data = NULL,
            .datatype = UNKNOWN
        };
    }

    const char *word = &p->content[p->y][p->x][p->cursor];
    struct result res = {
        .success = false,
        .size = 0,
        .data = NULL
    };
    char *buf = NULL;
    size_t letter_index = 0;

    for (size_t i = 0; word[i]; i++) {
        if (is_alpha(word[i])) {
            letter_index++;
        } else {
            break;
        }
    }
    buf = malloc(sizeof(char) * (letter_index + 1));
    memset(buf, 0, sizeof(char) * (letter_index + 1));
    strncpy(buf, word, letter_index);
    res = (struct result) {
        .size = 1,
        .success = true,
        .data = buf,
        .datatype = STRING
    };
    p->cursor += letter_index;
    return res;
}
