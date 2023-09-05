#include "grammar/condition.h"
#include "logger.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static struct result *if_keyword(struct parser *p)
{
    logger().cpt_debug("if_keyword\n");

    struct result *res = alpha_word(p);

    if (!res) {
        logger().cpt_debug("if_keyword: no res\n");
        return NULL;
    }
    if (strcmp(res->data, "if") != 0) {
        logger().cpt_debug("if_keyword: not if\n");
        return NULL;
    }
    logger().cpt_debug("if_keyword: is if\n");
    return res;
}

static struct result *else_keyword(struct parser *p)
{
    logger().cpt_debug("else_keyword\n");

    struct result *res = alpha_word(p);

    if (!res) {
        return NULL;
    }
    if (strcmp(res->data, "else") != 0) {
        return NULL;
    }
    return res;
}

static struct result *cond_lines(struct parser *p)
{
    logger().cpt_debug("cond_lines\n");
    logger().cpt_debug("cursor %d %d %d %d\n", p->pos.x, p->pos.y, p->pos.cursor, p->tokens[p->pos.y][p->pos.x][p->pos.cursor]);
    struct result *res = zero_or_more(p, expr);
    logger().cpt_debug("cond_lines: end, size: %d\n", res->size);
    return res;
}

static struct result *cond_body(struct parser *p)
{
    logger().cpt_debug("cond_body\n");
    return sequence(
        p,
        (parser_func[]) {
            open_curly,
            cond_lines,
            close_curly
        },
        3
    );
}

static struct result *cond_value(struct parser *p)
{
    logger().cpt_debug("cond_value\n");
    return ordered_choice(p, (parser_func[]){
        third_expression,
        expr_value
    }, 2);
}

static struct result *if_condition(struct parser *p)
{
    logger().cpt_debug("if_condition\n");
    return sequence(
        p,
        (parser_func[]) {
            if_keyword,
            open_par,
            cond_value,
            close_par,
            cond_body,
        },
        5
    );
}

static struct result *if_or_body(struct parser *p)
{
    logger().cpt_debug("if_or_body\n");
    return ordered_choice(
        p,
        (parser_func[]) {
            condition,
            cond_body
        },
        2
    );
}

static struct result *else_condition(struct parser *p)
{
    logger().cpt_debug("else_condition\n");
    return sequence(
        p,
        (parser_func[]) {
            else_keyword,
            if_or_body,
        },
        2
    );
}

static struct result *maybe_else_condition(struct parser *p)
{
    logger().cpt_debug("maybe_else_condition\n");
    struct result *res = zero_or_one(p, else_condition);
    logger().cpt_debug("maybe_else_condition: end\n");
    logger().cpt_debug("maybe_else_condition: res %d\n", res->datatype);
    return res;
}

struct result *condition(struct parser *p)
{
    save(p);
    logger().cpt_debug("condition\n");

    struct condition_cpt *ret = malloc(sizeof(struct condition_cpt));
    struct result *parsed = sequence(
        p,
        (parser_func[]) {
            if_condition,
            maybe_else_condition
        },
        2
    );

    if (!parsed) {
        logger().cpt_debug("condition: no parsed\n");
        rollback(p);
        return NULL;
    }

    struct result *parsed_data = (struct result *)parsed->data;
    struct result *if_block, *if_datas, *if_cond, *if_keyword;
    struct result *if_body, *if_body_datas, *if_body_data;
    struct result *else_block, *else_body = NULL;

    if_block = &parsed_data[0];
    else_block = &parsed_data[1];
    if (else_block->datatype != UNKNOWN) {
        struct result *else_datas = (struct result *)else_block->data;
        struct result *keyword, *body;

        keyword = &else_datas[0];
        body = &else_datas[1];
        logger().cpt_debug("else block\n");
        logger().cpt_debug("else keyword %d %s\n", keyword->datatype, keyword->data);
        logger().cpt_debug("body %d %d\n", body->datatype, body->size);
        if (body->datatype == CONDITION) {
            logger().cpt_debug("else body is condition\n");
            else_body = body;
        } else {
            struct result *datas = (struct result *)body->data;

            logger().cpt_debug("else body is not condition\n");
            else_body = &datas[1];
            logger().cpt_debug("else body %d %d\n", else_body->datatype, else_body->size);
        }
    } else {
        logger().cpt_debug("no else block\n");
    }
    if_datas = if_block->data;
    if_keyword = &if_datas[0];
    if_cond = &if_datas[2];
    if_body = &if_datas[4];
    if_body_datas = (struct result *)if_body->data;
    if_body_data = &if_body_datas[1];
    logger().cpt_debug("if_boddy %d %d\n", if_body_data->datatype, if_body_data->size);
    *ret = (struct condition_cpt) {
        .keyword = if_keyword->data,
        .cond = if_cond,
        .body = if_body_data,
        .else_stmt = else_body
    };
    delete_save(p);
    return result(ret, CONDITION, 1);
}
