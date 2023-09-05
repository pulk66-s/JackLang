#include "print/cpt/comparison.h"
#include "print/cpt/repartition.h"
#include "logger.h"

void print_comparison(struct result *r)
{
    struct comparison_cpt *res = r->data;

    logger().cpt("\"comparison\": {\n");
    logger().cpt("\"operator\": \"%s\",\n", res->comp);
    logger().cpt("\"left\": {\n");
    repartition(res->left);
    logger().cpt("},\n");
    logger().cpt("\"right\": {\n");
    repartition(res->right);
    logger().cpt("}\n");
    logger().cpt("},\n");
}