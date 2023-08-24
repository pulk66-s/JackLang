#include "grammar/program.h"
#include "grammar/default.h"
#include "grammar/expr.h"

struct result program(struct packrat *p)
{
    return zero_or_more(p, expr);
}
