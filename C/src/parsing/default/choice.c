#include "parsing/default/choice.h"
#include "parsing/default/char.h"

/**
 * @brief           The choice parser, it tries to parse the input with the left parser
 *                  if it fails, it tries with the next parser, and stops when it finds
 *                  a parser that succeeds
 * @param   parser  The parser
 * @param   funcs   The parsers to try
 * @param   size    The number of parsers to try
 * @return          The result of the first parser that succeeds, or NULL if all parsers failed
*/
struct result *ordered_choice(struct parser *parser, parser_func *funcs, size_t size)
{
    struct result *res = NULL;

    for (size_t i = 0; i < size; i++) {
        save(parser);
        res = funcs[i](parser);
        if (res != NULL) {
            delete_save(parser);
            return res;
        }
        rollback(parser);
    }
    return NULL;
}

/**
 * @brief           The sequence parser, it tries to parse all the parsers in the
 *                  Given order, if one fails, it stops and returns NULL
 * @param   parser  The parser
 * @param   funcs   The parsers to try
 * @param   size    The number of parsers to try
 * @return          The result of all the parsers, or NULL if one failed
*/
struct result *sequence(struct parser *parser, parser_func *funcs, size_t size)
{
    struct result *res = malloc(sizeof(struct result));

    *res = (struct result) {
        .datatype = EXPR,
        .data = NULL,
        .size = 0
    };
    save(parser);
    for (size_t i = 0; i < size; i++) {
        struct result *sub_res = funcs[i](parser);

        if (sub_res == NULL) {
            rollback(parser);
            return NULL;
        }
        res->size++;
        if (!res->data) {
            res->data = malloc(sizeof(struct result) * res->size);
        } else {
            res->data = realloc(res->data, sizeof(struct result) * res->size);
        }
        ((struct result *)res->data)[res->size - 1] = *sub_res;
    }
    delete_save(parser);
    return res;
}
