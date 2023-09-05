#include "grammar/variables.h"
#include "grammar/type.h"
#include "grammar/expr.h"
#include "logger.h"
#include <stdlib.h>

static struct result *variable_value(struct parser *p)
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

struct result *variable_declaration(struct parser *p)
{
    logger().cpt_debug("variable_declaration\n");
    save(p);

    struct result *res = sequence(
        p,
        (parser_func[]){
            type,
            identifier,
            equal,
            variable_value
        },
        4
    );
    struct result *datas, *type, *identifier, *value;
    struct variable_decl_cpt *cpt = malloc(sizeof(struct variable_decl_cpt));

    logger().cpt_debug("variable declaration after sequence\n");
    if (!res) {
        logger().cpt_debug("variable_declaration: NULL\n");
        rollback(p);
        return NULL;
    }
    logger().cpt_debug("res size: %d\n", res->size);
    datas = (struct result *)res->data;
    type = &datas[0];
    identifier = &datas[1];
    value = &datas[3];
    logger().cpt_debug("variable decl, type: %d, identifier: %d, value: %d\n", type->datatype, identifier->datatype, value->datatype);
    *cpt = (struct variable_decl_cpt){
        .type = type->data,
        .identifier = identifier->data,
        .value = value
    };
    delete_save(p);
    return result(cpt, VARIABLE_DECL, 1);
}

static struct result *operator(struct parser *p)
{
    return ordered_choice(
        p,
        (parser_func[]) {
            equal,
            plus_equal,
            minus_equal,
            star_equal,
            slash_equal,
            percent_equal
        },
        6
    );
}

struct result *variable_redeclaration(struct parser *p)
{
    logger().cpt_debug("variable_redeclaration\n");
    save(p);

    struct result *res = sequence(
        p,
        (parser_func[]){
            identifier,
            operator,
            variable_value
        },
        3
    );
    struct result *datas, *operator;
    struct variable_redecl_cpt *cpt = malloc(sizeof(struct variable_redecl_cpt));

    if (!res) {
        logger().cpt_debug("variable_redeclaration: NULL\n");
        rollback(p);
        return NULL;
    }
    datas = (struct result *)res->data;
    operator = &datas[1];
    if (operator->datatype == CHAR) {
        char op = *(char *)operator->data;
        operator->data = malloc(sizeof(char) * 2);
        ((char *)operator->data)[0] = op;
        ((char *)operator->data)[1] = 0;
    }
    *cpt = (struct variable_redecl_cpt){
        .identifier = datas[0].data,
        .operator = operator->data,
        .value = &datas[2]
    };
    delete_save(p);
    logger().cpt_debug("variable_redeclaration: success\n");
    return result(cpt, VARIABLE_REDECL, 1);
}
