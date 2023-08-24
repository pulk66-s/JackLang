#ifndef __CL_GRAMMAR_TYPES_H__
#define __CL_GRAMMAR_TYPES_H__

#include <stddef.h>
#include <stdbool.h>

enum result_data_type {
    STRING,
    CHAR,
    UNKNOWN,
    EXPR_STATEMENT,
    OPERATION,
    NUMBER,
    PROGRAM,
    FUNCTION_DECL
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

#define FAIL_RESULT (struct result) { \
    .success = false, \
    .size = 0, \
    .data = NULL, \
    .datatype = UNKNOWN \
}
#define DEFAULT_RESULT FAIL_RESULT

typedef struct result (*expr_t)(struct packrat *p);

char next(struct packrat *p);
void prev(struct packrat *p);
void next_word(struct packrat *p);

#endif
