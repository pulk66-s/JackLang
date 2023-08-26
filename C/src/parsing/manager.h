#ifndef __CL_PARSING_MANAGER_H__
#define __CL_PARSING_MANAGER_H__

#include <stdlib.h>

struct pos {
    size_t x;
    size_t y;
    size_t cursor;
};

struct save_pos {
    struct pos pos;
    struct save_pos *next;
};

struct parser {
    struct pos pos;
    struct save_pos *save_pos;
    const char ***tokens;
};

enum cpt_type {
    NUMBER,
    CHAR
};

struct result {
    size_t size;
    enum cpt_type datatype;
    void *data;
};

/**
 * @brief           Initialize the parsing structure
 * @param   tokens  The tokens of the program
 * @return          The parsing structure
*/
struct parser init(const char ***tokens);

#endif
