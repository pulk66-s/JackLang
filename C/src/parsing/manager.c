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
