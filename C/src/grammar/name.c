#include "grammar/name.h"
#include "grammar/word.h"
#include "grammar/default.h"
#include <string.h>
#include <stdlib.h>

struct result name(struct packrat *p)
{
    struct result res = sequence(
        p,
        (expr_t[]) {
            alpha_letter,
            alphanumeric
        },
        2
    );

    if (!res.success) {
        return FAIL_RESULT;
    }

    struct result *datas = res.data;
    struct result *alpha_res = &datas[0];
    struct result *alphanum_res = &datas[1];
    size_t buff_size = strlen(alphanum_res->data) + 2;
    char *buff = malloc(buff_size);

    memset(buff, 0, buff_size);
    *buff = *(char *)alpha_res->data;
    strcat(buff, alphanum_res->data);
    return (struct result) {
        .success = true,
        .size = 1,
        .data = buff,
        .datatype = STRING
    };
}
