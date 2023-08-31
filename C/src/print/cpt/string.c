#include "print/cpt/string.h"
#include "logger.h"

void print_string(struct result *res)
{
    if (res->datatype != VAR) {
        logger().cpt_debug("print_string: res->datatype != VAR");
        return;
    }
    logger().cpt("\"String\": \"%s\",\n", (char *)res->data);
}