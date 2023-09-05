#include "parsing/words/keywords.h"
#include "parsing/manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct result *keyword(struct parser *p, char *keyword)
{
    save(p);
    char *data = malloc(sizeof(char) * (strlen(keyword) + 1));

    memset(data, 0, sizeof(char) * (strlen(keyword) + 1));
    for (size_t i = 0; keyword[i]; i++) {
        char c = next(p);
        if (c != keyword[i]) {
            rollback(p);
            return NULL;
        }
        data[i] = c;
    }
    delete_save(p);
    return result(data, KEYWORD, 1);
}

struct result *plus_equal(struct parser *p)
{
    return keyword(p, "+=");
}

struct result *minus_equal(struct parser *p)
{
    return keyword(p, "-=");
}

struct result *star_equal(struct parser *p)
{
    return keyword(p, "*=");
}

struct result *slash_equal(struct parser *p)
{
    return keyword(p, "/=");
}

struct result *percent_equal(struct parser *p)
{
    return keyword(p, "%=");
}
