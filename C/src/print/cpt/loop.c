#include "print/cpt/repartition.h"
#include "print/cpt/loop.h"
#include "logger.h"

void print_loop_cpt(struct result *r)
{
    struct loop_cpt *loop = r->data;

    logger().cpt("\"loop\": {\n");
    logger().cpt("\"keyword\": \"%s\",\n", loop->keyword);
    if (loop->start) {
        logger().cpt("\"start\": {\n");
        repartition(loop->start);
        logger().cpt("},\n");
    } else {
        logger().cpt("\"start\": null,\n");
    }
    logger().cpt("\"condition\": {\n");
    repartition(loop->cond);
    logger().cpt("},\n");
    if (loop->iter) {
        logger().cpt("\"iter\": {\n");
        repartition(loop->iter);
        logger().cpt("},\n");
    } else {
        logger().cpt("\"iter\": null,\n");
    }
    logger().cpt("\"body\": {\n");
    repartition(loop->body);
    logger().cpt("}\n");
    logger().cpt("},\n");
}
