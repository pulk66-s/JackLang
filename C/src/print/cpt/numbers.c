#include "print/cpt/numbers.h"
#include "logger.h"

void print_numbers(struct result *res)
{
    if (res->datatype != NUMBER) {
        logger().cpt_debug("print_numbers: res->datatype != NUMBER");
        return;
    }
    logger().cpt("\"Number\": %d,\n", *(int *)res->data);
}
