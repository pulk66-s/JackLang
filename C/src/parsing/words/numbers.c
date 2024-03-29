#include "parsing/words/numbers.h"
#include "parsing/words/letters.h"
#include "parsing/default/char.h"
#include "logger.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief       Parse a number.
 * @details     A number is a sequence of digits.
 * @param   p   The parser.
 * @return      The result of the parsing.
*/
struct result *number(struct parser *p)
{
    logger().cpt_debug("number\n");

    size_t size = 0;
    char *buf;
    int number;
    int *number_ptr;

    save(p);
    for (; is_digit(next(p)); size++);
    rollback(p);
    if (size == 0) {
        logger().cpt_debug("Error: number expected\n");
        return NULL;
    }
    number_ptr = malloc(sizeof(int));
    buf = malloc(sizeof(char) * (size + 1));
    memset(buf, 0, sizeof(char) * (size + 1));
    for (size_t i = 0; i < size; i++) {
        buf[i] = next(p);
    }
    number = atoi(buf);
    *number_ptr = number;
    logger().cpt_debug("number: %d\n", number);
    return result(number_ptr, NUMBER, 1);
}
