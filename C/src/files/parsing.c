#include "files/parsing.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

static size_t count_nb_words(const char *str, char c)
{
    size_t nb_words = 0;

    for (; str[0] && str[0] == c; str++);
    for (size_t i = 0; str[i + 1]; i++) {
        if (str[i] == c && str[i + 1] != c) {
            nb_words++;
        }
    }
    return nb_words + 1;
}

static char **splitting(const char *str, char c)
{
    size_t nb_words = count_nb_words(str, c);
    char **buf = malloc(sizeof(char *) * (nb_words + 1));

    if (!buf) {
        return NULL;
    }
    buf[nb_words] = NULL;
    for (size_t i = 0; i < nb_words; i++) {
        size_t len = 0;

        for (; str[0] && str[0] == c; str++);
        for (; str[len] && str[len] != c; len++);
        buf[i] = malloc(sizeof(char) * (len + 1));
        if (!buf[i]) {
            return NULL;
        }
        strncpy(buf[i], str, len);
        buf[i][len] = '\0';
        str += len;
    }
    return buf;
}

static char **create_line(char *line)
{
    char **buf = splitting(line, ' ');

    if (!buf) {
        return NULL;
    }
    return buf;
}

const char ***parse_content(const char *content)
{
    size_t nb_lines = count_nb_words(content, '\n');
    char ***buf = malloc(sizeof(char **) * (nb_lines + 1));
    char **lines = NULL;

    if (!buf) {
        return NULL;
    }
    buf[nb_lines] = NULL;
    lines = splitting(content, '\n');
    if (!lines) {
        return NULL;
    }
    for (size_t i = 0; i < nb_lines; i++) {
        buf[i] = create_line(lines[i]);
    }
    return (const char ***)buf;
}
