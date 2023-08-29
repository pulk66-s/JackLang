#include "grammar/type.h"

struct result *type(struct parser *p)
{
    return alpha_word(p);
}