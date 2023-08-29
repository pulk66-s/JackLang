#include "parsing/words/special_char.h"
#include "parsing/default.h"

static struct result *special_char(struct parser *p, char c)
{
    char cc;

    save(p);
    cc = next(p);
    if (cc == c) {
        char *buf = malloc(sizeof(char) * 2);

        buf[0] = c;
        buf[1] = '\0';
        delete_save(p);
        return result(buf, CHAR, 1);
    }
    rollback(p);
    return NULL;
}

struct result *semicolon(struct parser *p)
{
    return special_char(p, ';');
}

struct result *open_par(struct parser *p)
{
    return special_char(p, '(');
}

struct result *close_par(struct parser *p)
{
    return special_char(p, ')');
}

struct result *open_curly(struct parser *p)
{
    return special_char(p, '{');
}

struct result *close_curly(struct parser *p)
{
    return special_char(p, '}');
}

struct result *comma(struct parser *p)
{
    return special_char(p, ',');
}