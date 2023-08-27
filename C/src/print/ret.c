#include "print/ret.h"
#include "logger.h"
#include "repartition.h"

void print_ret(struct result *r)
{
    struct return_cpt *ret_cpt = r->data;

    if (!r || r->datatype != RET) {
        logger().syntax_debug("print_ret: NULL or wrong type passed");
        return;
    }
    logger().syntax("\"Return\": {\n");
    logger().syntax("\"Keyword\": ");
    logger().syntax("\"%s\",\n", ret_cpt->keyword);
    logger().syntax("\"Expr\": {\n");
    repartition(ret_cpt->expr);
    logger().syntax("}\n},\n");
}
