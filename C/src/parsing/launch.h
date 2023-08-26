#ifndef __CL_PARSING_LAUNCH_H__
#define __CL_PARSING_LAUNCH_H__

#include "parsing/prgm.h"

/**
 * @brief           Launch the parsing of the program
 * @param   tokens  The tokens of the program
 * @return          The CPT of the program
 */
struct prgm_cpt *launch_parsing(const char ***tokens);

#endif
