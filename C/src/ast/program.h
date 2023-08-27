#ifndef __CL_AST_PRGM_H__
#define __CL_AST_PRGM_H__

#include "ast/lines.h"

struct program_ast {
    struct line_ast **lines;
};

#endif