#include "grammar/type.h"
#include "logger.h"

struct result *type(struct parser *p)
{
    logger().cpt_debug("type\n");

    struct result *res = alpha_word(p);

    if (!res) {
        logger().cpt_debug("type: NULL\n");
        return NULL;
    }
    logger().cpt_debug("type: %s\n", res->data);
    return res;
}