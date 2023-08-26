#ifndef __CL_PARSING_LAUNCH_H__
#define __CL_PARSING_LAUNCH_H__

#include "grammar.h"

/**
 * @brief           Launch the parsing of the program
 * @param   tokens  The tokens of the program
 * @return          The CPT of the program
 */
struct result *launch_parsing(const char ***tokens);

#endif
