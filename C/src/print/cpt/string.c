#include "print/cpt/string.h"
#include "logger.h"

void print_string(struct result *res)
{
    if (res->datatype != STRING) {
        logger().cpt_debug("print_string: res->datatype != STRING");
        return;
    }
    logger().cpt("\"String\": \"%s\",\n", (char *)res->data);
}