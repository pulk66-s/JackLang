#include "words.h"
#include <stdlib.h>

struct packrat_result letter(struct packrat *pr)
{
    char c = next(pr);
    bool result = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    char *buff = malloc(2);

    buff[0] = c;
    buff[1] = 0;
    return (struct packrat_result) {
        .success = result,
        .value = buff
    };
}

struct packrat_result word(struct packrat *pr)
{
    return one_or_more(pr, letter);
}