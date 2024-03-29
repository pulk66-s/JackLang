#include "print/cpt/repartition.h"
#include "print/cpt/function.h"
#include "logger.h"

void print_function(struct result *r)
{
    if (r->datatype != FUNCTION_DECL) {
        logger().cpt_debug("print_function: r->datatype != FUNCTION_DECL");
        return;
    }

    struct function_decl_cpt *f = r->data;

    logger().cpt("\"function_decl\": {\n");
    logger().cpt("\"type\": \"%s\",\n", f->type);
    logger().cpt("\"name\": \"%s\",\n", f->name);
    logger().cpt("\"args\": [\n");
    for (size_t i = 0; f->args[i]; i++) {
        logger().cpt("{\n");
        logger().cpt("\"type\": \"%s\",\n", f->args[i]->type);
        logger().cpt("\"name\": \"%s\"\n", f->args[i]->name);
        logger().cpt("}%s\n", f->args[i + 1] ? "," : "");
    }
    logger().cpt("],\n");
    logger().cpt("\"lines\": [\n");
    logger().cpt("{\n");
    repartition(f->lines);
    logger().cpt("}\n");
    logger().cpt("],\n");
    logger().cpt("}\n");
}

void print_function_call(struct result *r)
{
    if (r->datatype != FUNCTION_CALL) {
        logger().cpt_debug("print_function_call: r->datatype != FUNCTION_CALL");
        return;
    }

    struct function_call_cpt *f = r->data;

    logger().cpt("\"function_call\": {\n");
    logger().cpt("\"name\": \"%s\",\n", f->identifier);
    logger().cpt("\"args\": [\n");
    logger().cpt("{\n");
    repartition(f->args);
    logger().cpt("},\n");
    logger().cpt("]\n");
    logger().cpt("}\n");
}