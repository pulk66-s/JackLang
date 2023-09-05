#include "logger.h"
#include "grammar/comparison.h"
#include "grammar/operation.h"
#include <stdlib.h>
#include <string.h>

static struct result *left_value(struct parser *p)
{
    return expr_value(p);
}

static struct result *get_comparison_op(struct parser *p)
{
    char *buf = malloc(sizeof(char) * 3);
    struct result *res = malloc(sizeof(struct result));

    buf[0] = next(p);
    logger().cpt_debug("buf[0] = '%c'\n", buf[0]);
    if (buf[0] == '>' || buf[0] == '<') {
        buf[1] = 0;
        res->data = buf;
        res->datatype = KEYWORD;
        return res;
    }
    buf[1] = next(p);
    logger().cpt_debug("buf[1] = '%c'\n", buf[1]);
    buf[2] = 0;
    res->data = buf;
    res->datatype = KEYWORD;
    res->size = 1;
    return res;
}

static struct result *comparison_op(struct parser *p)
{
    logger().cpt_debug("comparison_op\n");

    struct result *res = get_comparison_op(p);
    char *operators[] = {
        "==",
        "!=",
        ">",
        "<",
        ">=",
        "<="
    };

    if (!res) {
        logger().cpt_debug("comparison_op: failed\n");
        return NULL;
    }
    for (int i = 0; i < 6; i++) {
        logger().cpt_debug("comparison_op: compare \"%s\" with \"%s\"\n", res->data, operators[i]);
        if (strcmp(res->data, operators[i]) == 0) {
            logger().cpt_debug("comparison_op: success\n");
            return res;
        }
    }
    logger().cpt_debug("comparison_op: failed, operator=\"%s\"\n", res->data);
    return NULL;
}

static struct result *right_value(struct parser *p)
{
    return ordered_choice(p, (parser_func[]){
        third_expression,
        expr_value
    }, 2);
}

struct result *comparison(struct parser *p)
{
    struct result *res, *datas, *keyword, *left, *right;
    struct comparison_cpt *ret;

    logger().cpt_debug("comparison\n");
    save(p);
    res = sequence(p, (parser_func[]){left_value, comparison_op, right_value}, 3);
    if (!res) {
        logger().cpt_debug("comparison: failed\n");
        rollback(p);
        return NULL;
    }
    ret = malloc(sizeof(struct comparison_cpt));
    memset(ret, 0, sizeof(struct comparison_cpt));
    datas = res->data;
    left = &datas[0];
    keyword = &datas[1];
    right = &datas[2];
    *ret = (struct comparison_cpt){
        .comp = keyword->data,
        .left = left,
        .right = right
    };
    logger().cpt_debug("comparison: success %s\n", keyword->data);
    delete_save(p);
    return result(ret, COMPARISON, 1);
}
