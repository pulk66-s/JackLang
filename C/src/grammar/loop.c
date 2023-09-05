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

static struct result *for_keyword(struct parser *p)
{
    logger().cpt_debug("for_keyword\n");
    struct result *res = alpha_word(p);

    if (!res) {
        logger().cpt_debug("for_keyword failed on parse\n");
        return NULL;
    }
    if (strcmp(res->data, "for") != 0) {
        logger().cpt_debug("for_keyword failed on strcmp\n");
        return NULL;
    }
    logger().cpt_debug("for_keyword success\n");
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

static struct result *for_init(struct parser *p)
{
    logger().cpt_debug("for_init\n");
    struct result *res = third_expression(p);

    if (!res) {
        logger().cpt_debug("for_init failed on parse\n");
        return NULL;
    }
    logger().cpt_debug("for_init success\n");
    return res;
}

static struct result *for_cond(struct parser *p)
{
    logger().cpt_debug("for_cond\n");
    struct result *res = third_expression(p);

    if (!res) {
        logger().cpt_debug("for_cond failed on parse\n");
        return NULL;
    }
    logger().cpt_debug("for_cond success\n");
    return res;
}

static struct result *for_iter(struct parser *p)
{
    logger().cpt_debug("for_iter\n");
    struct result *res = third_expression(p);

    if (!res) {
        logger().cpt_debug("for_iter failed on parse\n");
        return NULL;
    }
    logger().cpt_debug("for_iter success\n");
    return res;
}

static struct result *for_body(struct parser *p)
{
    logger().cpt_debug("for_body\n");
    struct result *res = zero_or_more(p, secondary_expression);

    if (!res) {
        logger().cpt_debug("for_body failed on parse\n");
        return NULL;
    }
    logger().cpt_debug("for_body success\n");
    return res;
}

static struct result *for_loop(struct parser *p)
{
    logger().cpt_debug("for_loop\n");
    struct result *res  = sequence(
        p,
        (parser_func[]) {
            for_keyword,
            open_par,
            for_init,
            semicolon,
            for_cond,
            semicolon,
            for_iter,
            close_par,
            open_curly,
            for_body,
            close_curly
        },
        11
    );

    if (!res) {
        logger().cpt_debug("for_loop failed on parse\n");
        return NULL;
    }
    logger().cpt_debug("for_loop success\n");
    return res;
}

struct result *loop(struct parser *p)
{
    save(p);
    struct result *res;
    struct loop_cpt *cpt = malloc(sizeof(struct loop_cpt));
    struct result *datas, *keyword, *cond, *body, *iter, *start;

    logger().cpt_debug("loop\n");
    res = ordered_choice(p, (parser_func[]) { while_loop, for_loop }, 2);
    if (!res) {
        rollback(p);
        logger().cpt_debug("loop failed\n");
        return NULL;
    }
    datas = (struct result *)res->data;
    if (res->size == 7) {
        keyword = &datas[0];
        cond = &datas[2];
        body = &datas[5];
        iter = NULL;
        start = NULL;
    } else {
        keyword = &datas[0];
        start = &datas[2];
        cond = &datas[4];
        iter = &datas[6];
        body = &datas[9];
    }
    *cpt = (struct loop_cpt) {
        .body = body,
        .cond = cond,
        .iter = iter,
        .start = start,
        .keyword = keyword->data
    };
    delete_save(p);
    logger().cpt_debug("loop success\n");
    return result(cpt, LOOP, 1);
}
