#include "grammar/function/function_call.h"
#include "grammar/expr.h"
#include "logger.h"

static struct result *arg_value(struct parser *p)
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

static struct result *arg(struct parser *p)
{
    return sequence(
        p,
        (parser_func[]) {
            arg_value,
            comma
        },
        2
    );
}

static struct result *function_call_args(struct parser *p)
{
    save(p);
    logger().cpt_debug("function_call_args\n");
    struct result *res = zero_or_more(p, arg);
    struct result *last_arg = arg_value(p);
    struct result *ret = malloc(sizeof(struct result));

    if (res->size > 0 && !last_arg) {
        logger().cpt_debug("function_call_args: FAIL, res.size > 0 and !last_arg\n");
        rollback(p);
        return NULL;
    }
    *ret = (struct result) {
        .datatype = EXPR,
        .size = res->size + (last_arg ? 1 : 0),
        .data = malloc(sizeof(struct result) * (res->size + (last_arg ? 1 : 0)))
    };
    for (size_t i = 0; i < res->size; i++) {
        ((struct result *)ret->data)[i] = ((struct result *)res->data)[i];
    }
    if (last_arg) {
        ((struct result *)ret->data)[res->size] = *last_arg;
    }
    delete_save(p);
    logger().cpt_debug("function_call_args: SUCCESS\n");
    return ret;
}

struct result *function_call(struct parser *p)
{
    save(p);
    logger().cpt_debug("function_call\n");
    logger().cpt_debug("cursor: %d %d %d\n", p->pos.x, p->pos.y, p->pos.cursor);
    struct result *res = sequence(
        p,
        (parser_func[]) {
            identifier,
            open_par,
            function_call_args,
            close_par
        },
        4
    );
    struct function_call_cpt *cpt = malloc(sizeof(struct function_call_cpt));
    struct result *datas, *args, *identifier;

    if (!res) {
        logger().cpt_debug("function_call: NULL\n");
        rollback(p);
        return NULL;
    }
    datas = (struct result *)res->data;
    identifier = &datas[0];
    args = &datas[2];
    *cpt = (struct function_call_cpt) {
        .identifier = identifier->data,
        .args = args
    };
    delete_save(p);
    logger().cpt_debug("function_call: SUCCESS\n");
    return result(cpt, FUNCTION_CALL, 1);
}
