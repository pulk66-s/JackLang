#ifndef __CL_GRAMMAR_VARIABLES_H__
#define __CL_GRAMMAR_VARIABLES_H__

#include "parsing.h"

struct variable_decl_cpt {
    char *type;
    char *identifier;
    struct result *value;
};

struct result *variable_declaration(struct parser *p);

#endif
