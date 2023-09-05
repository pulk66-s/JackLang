#include "print/cpt/keyword.h"
#include "logger.h"

void print_keyword(struct result *keyword)
{
    logger().cpt("\"keyword\": \"%s\",\n", keyword->data);
}
