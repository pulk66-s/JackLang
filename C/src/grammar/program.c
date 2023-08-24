#include "grammar/program.h"
#include "grammar/default.h"
#include "grammar/word.h"

struct result program(struct packrat *p)
{
    return zero_or_more(p, word);
}
