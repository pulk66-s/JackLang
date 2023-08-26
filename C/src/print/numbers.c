#include "print/numbers.h"
#include "logger.h"

void print_numbers(struct result *res)
{
    if (res->datatype != NUMBER) {
        logger().syntax_debug("print_numbers: res->datatype != NUMBER");
        return;
    }
    logger().syntax("\"Number\": %d,\n", *(int *)res->data);
}
