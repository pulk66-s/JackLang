#include "parsing/words/words.h"
#include "parsing/default/char.h"
#include "parsing/words/letters.h"
#include "logger.h"
#include <stdlib.h>
#include <string.h>

static bool next_word(struct pos curr, struct pos save)
{
    return curr.x != save.x || curr.y != save.y;
}

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
    struct pos saved;

    logger().cpt_debug("alpha_word\n");
    save(p);
    next(p);
    saved = p->pos;
    rollback(p);
    save(p);
    while (true) {
        char c = next(p);

        if (!is_alpha(c) && !is_digit(c) && c != '_') {
            break;
        }
        if (next_word(p->pos, saved)) {
            break;
        }
        size++;
    }
    rollback(p);
    buf = malloc(sizeof(char) * (size + 1));
    memset(buf, 0, sizeof(char) * (size + 1));
    for (size_t i = 0; i < size; i++) {
        buf[i] = next(p);
    }
    logger().cpt_debug("alpha_word: %s\n", buf);
    return result(buf, KEYWORD, 1);
}

struct result *identifier(struct parser *p)
{
    logger().cpt_debug("identifier\n");

    size_t size = 0;
    char *buf;
    char first_c;
    struct pos saved;

    save(p);
    first_c = next(p);
    saved = p->pos;
    if (!is_alpha(first_c) && first_c != '_') {
        rollback(p);
        logger().cpt_debug("identifier: NULL\n");
        return NULL;
    }
    size++;
    while (true) {
        char c = next(p);

        if (!is_alpha(c) && !is_digit(c) && c != '_') {
            break;
        }
        if (next_word(p->pos, saved)) {
            break;
        }
        size++;
    }
    rollback(p);
    buf = malloc(sizeof(char) * (size + 1));
    memset(buf, 0, sizeof(char) * (size + 1));
    for (size_t i = 0; i < size; i++) {
        buf[i] = next(p);
    }
    logger().cpt_debug("identifier: %s\n", buf);
    return result(buf, VAR, 1);
}
