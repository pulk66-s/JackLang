#include "parsing/words/letters.h"
#include "parsing/manager.h"
#include "parsing/default/char.h"

/**
 * @brief       Parse an alpha character
 * @param   p   The parsing structure
 * @return      The result of the parsing
 *  - NULL if the parsing failed
 *  - A result structure if the char is an alpha character
*/
struct result *alpha(struct parser *p)
{
    char c;
    struct result *res;
    char *buff;

    save(p);
    c = next(p);
    if (!is_alpha(c)) {
        rollback(p);
        return NULL;
    }
    res = malloc(sizeof(struct result));
    buff = malloc(sizeof(char) * 2);
    buff[0] = c;
    buff[1] = '\0';
    *res = (struct result) {
        .size = 1,
        .datatype = CHAR,
        .data = buff
    };
    return res;
}

/**
 * @brief       Check if a char is an alpha character
 * @param   c   The char to check
 * @return      1 if the char is an alpha character else 0
*/
inline bool is_alpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
