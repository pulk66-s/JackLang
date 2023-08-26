#include "parsing/words/words.h"
#include "parsing/default/char.h"
#include "parsing/words/letters.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief       Parse a word.
 * @details     A word is a sequence of alpha characters that are not whitespace.
 * @param   p   The parser.
 * @return      The result of the parsing.
*/
struct result *alpha_word(struct parser *p)
{
    size_t size = 0;
    char *buf;

    save(p);
    for (; is_alpha(next(p)); size++);
    rollback(p);
    buf = malloc(sizeof(char) * (size + 1));
    memset(buf, 0, sizeof(char) * (size + 1));
    for (size_t i = 0; i < size; i++) {
        buf[i] = next(p);
    }
    return result(buf, STRING, 1);
}
