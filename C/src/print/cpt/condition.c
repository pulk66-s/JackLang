#include "print/cpt/repartition.h"
#include "print/cpt/condition.h"
#include "logger.h"

void print_if_stmt(struct result *res)
{
    struct condition_cpt *cpt = res->data;
    
    logger().cpt("\"if_stmt\": {\n");
    logger().cpt("\"keyword\": \"%s\",\n", cpt->keyword);
    logger().cpt("\"condition\": {\n");
    repartition(cpt->cond);
    logger().cpt("},\n");
    logger().cpt("\"body\": {\n");
    repartition(cpt->body);
    logger().cpt("},\n");
    if (cpt->else_stmt) {
        logger().cpt("\"else\": {\n");
        repartition(cpt->else_stmt);
        logger().cpt("},\n");
    }
    logger().cpt("}\n");
}