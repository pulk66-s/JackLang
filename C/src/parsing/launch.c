#include "parsing/launch.h"
#include "parsing/manager.h"
#include <stdlib.h>

/**
 * @brief           Launch the parsing of the program
 * @param   tokens  The tokens of the program
 * @return          The CPT of the program
 */
struct result *launch_parsing(const char ***tokens)
{
    struct parser parsing = init(tokens);

    return program(&parsing);
}
