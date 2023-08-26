#ifndef __CL_PARSING_DEFAULT_CHAR_H__
#define __CL_PARSING_DEFAULT_CHAR_H__

#include "parsing/manager.h"

/**
 * @brief       Get the next character of the program
 * @param   p   The parsing structure
 * @return      The next character of the program (0 if the end of the program is reached)
*/
char next(struct parser *p);

/**
 * @brief       Save the current position of the parser
 * @param   p   The parsing structure
*/
void save(struct parser *p);

/**
 * @brief       Restore the last saved position of the parser
 * @param   p   The parsing structure
*/
void rollback(struct parser *p);

/**
 * @brief       Delete the last saved position of the parser
 * @param   p   The parsing structure
*/
void delete_save(struct parser *p);

#endif
