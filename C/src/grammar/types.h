#ifndef __CL_GRAMMAR_TYPES_H__
#define __CL_GRAMMAR_TYPES_H__

#include <stddef.h>
#include <stdbool.h>

enum result_data_type {
    STRING,
    UNKNOWN
};

struct result {
    bool success;
    size_t size;
    void *data;
    enum result_data_type datatype;
};

struct packrat {
    size_t x;
    size_t y;
    size_t cursor;
    const char ***content;
};

typedef struct result (*expr_t)(struct packrat *p);

#endif
