#include "print/cpt/variables.h"
#include "print/cpt/repartition.h"
#include "logger.h"

void print_variable_decl(struct result *r)
{
    struct variable_decl_cpt *cpt = r->data;

    logger().cpt("\"variable_decl\": {\n");
    logger().cpt("\"type\": \"%s\",\n", cpt->type);
    logger().cpt("\"identifier\": \"%s\",\n", cpt->identifier);
    logger().cpt("\"value\": {\n");
    repartition(cpt->value);
    logger().cpt("},\n");
    logger().cpt("},\n");
}

void print_variable_redecl(struct result *r)
{
    struct variable_redecl_cpt *cpt = r->data;

    logger().cpt("\"variable_redecl\": {\n");
    logger().cpt("\"identifier\": \"%s\",\n", cpt->identifier);
    logger().cpt("\"value\": {\n");
    repartition(cpt->value);
    logger().cpt("},\n");
    logger().cpt("},\n");
}
