#include "grammar/program.h"
#include "grammar/default.h"
#include "grammar/expr.h"
#include "grammar/word.h"
#include "grammar/function.h"
#include "grammar/typing.h"
#include <stdlib.h>
#include <stdio.h>

struct result program(struct packrat *p)
{
    struct result res = zero_or_more(p, function_decl);

    if (!res.success) {
        return res;
    }
    return (struct result) {
        .data = res.data,
        .size = res.size,
        .success = true,
        .datatype = PROGRAM
    };
}
