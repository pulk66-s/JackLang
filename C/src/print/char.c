#include "print/char.h"
#include "logger.h"

void print_char(struct result *r)
{
    if (r->datatype != CHAR) {
        logger().cpt_debug("print_char: not a char");
        return;
    }
    logger().cpt("\"char\": \"%c\",\n", *(char *)r->data);
}