#include "print/cpt/ret.h"
#include "logger.h"
#include "repartition.h"

void print_ret(struct result *r)
{
    struct return_cpt *ret_cpt = r->data;

    if (!r || r->datatype != RET) {
        logger().cpt_debug("print_ret: NULL or wrong type passed");
        return;
    }
    logger().cpt("\"Return\": {\n");
    logger().cpt("\"Keyword\": \"%s\",\n",  ret_cpt->keyword);
    logger().cpt("\"Expr\": {\n");
    repartition(ret_cpt->expr);
    logger().cpt("}\n},\n");
}
