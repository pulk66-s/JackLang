#include "parsing/manager.h"

/**
 * @brief           Initialize the parsing structure
 * @param   tokens  The tokens of the program
 * @return          The parsing structure
*/
struct parser init(const char ***tokens)
{
    return (struct parser) {
        .pos = (struct pos) {
            .x = 0,
            .y = 0,
            .cursor = 0
        },
        .save_pos = NULL,
        .tokens = tokens,
    };
}

/**
 * @brief           Create a result structure
 * @param   data    The data of the result
 * @param   type    The type of the result
 * @param   size    The size of the result
 * @return          The result structure
*/
struct result *result(void *data, enum cpt_type type, size_t size)
{
    struct result *res = malloc(sizeof(struct result));

    *res = (struct result) {
        .size = size,
        .datatype = type,
        .data = data
    };
    return res;
}
