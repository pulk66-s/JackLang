#ifndef __CL_TESTS_UNITS_PACKRAT_INIT_H__
#define __CL_TESTS_UNITS_PACKRAT_INIT_H__

#include "units/categories.h"

/**
 * @brief   Initialize the category that tests the packrat parser
 * @return  The category
*/
struct category *init_packrat_category(void);

/**
 * @brief   Initialize the parsing unit tests
 * @return  The parsing struct
*/
struct parsing *init_packrat_parsing(const char ***tokens);

#endif