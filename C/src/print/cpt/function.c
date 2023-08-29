#include "print/cpt/repartition.h"
#include "print/cpt/function.h"
#include "logger.h"

void print_function(struct result *r)
{
    struct function_decl_cpt *f = r->data;

    logger().cpt("\"function_decl\": {\n");
    logger().cpt("\"name\": \"%s\",\n", f->name);
    logger().cpt("\"args\": [\n");
    repartition(f->args);
    logger().cpt("],\n");
    logger().cpt("\"lines\": [\n");
    repartition(f->lines);
    logger().cpt("],\n");
    logger().cpt("}\n");    
}
