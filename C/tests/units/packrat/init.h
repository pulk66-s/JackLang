#ifndef __CL_TESTS_UNITS_PACKRAT_INIT_H__
#define __CL_TESTS_UNITS_PACKRAT_INIT_H__

#include "units/categories.h"

/**
 * @brief   Initialize the category that tests the packrat parser
 * @return  The category
*/
struct category *init_default_category(void);

/**
 * @brief   Initialize the category that tests the words parser
 * @return  The category
*/
struct category *init_words_category(void);

/**
 * @brief   Initialize the parsing unit tests
 * @return  The parsing struct
*/
struct parser *init_packrat_parsing(const char ***tokens);

/**
 * @brief   Initialize the category that tests the numbers parser
 * @return  The category
*/
struct category *init_numbers_category(void);

/**
 * @brief   Initialize the category that tests the operation parser
 * @return  The category
*/
struct category *init_operations_category(void);

#endif