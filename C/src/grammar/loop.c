#include "grammar/loop.h"
#include "logger.h"
#include <string.h>
#include <stdlib.h>

static struct result *while_keyword(struct parser *p)
{
    logger().cpt_debug("while_keyword\n");
    struct result *res = alpha_word(p);

    if (!res) {
        logger().cpt_debug("while_keyword failed on parse\n");
        return NULL;
    }
    if (strcmp(res->data, "while") != 0) {
        logger().cpt_debug("while_keyword failed on strcmp\n");
        return NULL;
    }
    logger().cpt_debug("while_keyword success\n");
    return res;
}

static struct result *while_cond(struct parser *p)
{
    logger().cpt_debug("while_cond\n");
    struct result *res = third_expression(p);

    if (!res) {
        logger().cpt_debug("while_cond failed on parse\n");
        return NULL;
    }
    logger().cpt_debug("while_cond success\n");
    return res;
}

static struct result *while_body(struct parser *p)
{
    logger().cpt_debug("while_body\n");
    struct result *res = zero_or_more(p, secondary_expression);

    if (!res) {
        logger().cpt_debug("while_body failed on parse\n");
        return NULL;
    }
    logger().cpt_debug("while_body success\n");
    return res;
}

static struct result *while_loop(struct parser *p)
{
    return sequence(
        p,
        (parser_func[]) {
            while_keyword,
            open_par,
            while_cond,
            close_par,
            open_curly,
            while_body,
            close_curly
        },
        7
    );
}

struct result *loop(struct parser *p)
{
    struct result *res;
    struct loop_cpt *cpt = malloc(sizeof(struct loop_cpt));
    struct result *datas, *keyword, *cond, *body;

    logger().cpt_debug("loop\n");
    res = while_loop(p);
    if (!res) {
        logger().cpt_debug("loop failed\n");
        return NULL;
    }
    datas = (struct result *)res->data;
    keyword = &datas[0];
    cond = &datas[2];
    body = &datas[5];
    *cpt = (struct loop_cpt) {
        .body = body,
        .cond = cond,
        .iter = NULL,
        .start = NULL,
        .keyword = keyword->data
    };
    logger().cpt_debug("loop success\n");
    return result(cpt, LOOP, 1);
}
