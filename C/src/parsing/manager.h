#ifndef __CL_PARSING_MANAGER_H__
#define __CL_PARSING_MANAGER_H__

#include <stdlib.h>

struct pos {
    size_t x;
    size_t y;
    size_t cursor;
};

struct parsing {
    struct pos pos;
    const char ***tokens;
};

/**
 * @brief           Initialize the parsing structure
 * @param   tokens  The tokens of the program
 * @return          The parsing structure
*/
struct parsing init(const char ***tokens);

#endif