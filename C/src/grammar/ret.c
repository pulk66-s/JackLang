#include "grammar/ret.h"
#include "parsing/words.h"
#include "grammar/expr.h"
#include "logger.h"
#include <string.h>
#include <stdlib.h>

static struct result *ret_keyword(struct parser *p)
{
    struct result *r = alpha_word(p);

    if (!r || strcmp(r->data, "return") != 0) {
        return NULL;
    }
    return r;
}

static struct result *ret_expr(struct parser *p)
{
    return ordered_choice(
        p,
        (parser_func[]) {
            third_expression,
            expr_value
        },
        2
    );
}

/**
 * @brief       Parse a return statement
 * @param   p   Parser object
 * @return      Result object
*/
struct result *ret(struct parser *p)
{
    struct result *res;
    struct return_cpt *ret_cpt = malloc(sizeof(struct return_cpt));
    struct result *datas, *keyword, *expr;

    logger().cpt_debug("ret\n");
    save(p);
    res = sequence(
        p,
        (parser_func[]) {
            ret_keyword,
            ret_expr,
        },
        2
    );
    if (!res) {
        logger().cpt_debug("Error: return statement expected\n");
        rollback(p);
        return NULL;
    }
    delete_save(p);
    datas = res->data;
    keyword = &datas[0];
    expr = &datas[1];
    *ret_cpt = (struct return_cpt) {
        .keyword = keyword->data,
        .expr = expr,
    };
    return result(ret_cpt, RET, 1);
}
