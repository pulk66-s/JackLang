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
