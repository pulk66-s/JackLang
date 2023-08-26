#include "print/string.h"
#include "logger.h"

void print_string(struct result *res)
{
    if (res->datatype != STRING) {
        logger().syntax_debug("print_string: res->datatype != STRING");
        return;
    }
    logger().syntax("\"String\": \"%s\",\n", (char *)res->data);
}