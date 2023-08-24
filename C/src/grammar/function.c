#include "grammar/function.h"
#include "grammar/typing.h"
#include "grammar/word.h"
#include "grammar/default.h"
#include <stdlib.h>

struct result function_decl(struct packrat *p)
{
    struct result res = sequence(
        p,
        (expr_t[]) {
            type,
            word
        },
        2
    );
    struct function *fn = malloc(sizeof(struct function));
    struct result *type_res, *name_res;
    struct result *datas = res.data;

    if (!res.success) {
        return FAIL_RESULT;
    }
    type_res = &datas[0];
    name_res = &datas[1];
    *fn = (struct function) {
        .type = type_res->data,
        .name = name_res->data
    };
    return (struct result) {
        .success = true,
        .size = 1,
        .data = fn,
        .datatype = FUNCTION_DECL
    };
}
