#include "files/parsing.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

static size_t count(char c, const char *str)
{
    size_t occur = 0;

    for (size_t i = 0; str[i]; i++) {
        if (str[i] == c) {
            occur++;
        }
    }
    return occur;
}

static char *trim(char *str)
{
    for (; str[0] && str[0] == ' '; str++);

    size_t size = strlen(str);

    for (; size > 0 && str[size - 1] == ' '; size--);
    return str;
}

static char **create_line(const char *content, size_t line)
{
    size_t index = 0;
    char **buf = NULL;
    size_t nb_words = 0;

    for (size_t i = 0; i < line; index++) {
        if (content[index] == '\n') {
            i++;
        }
    }
    for (size_t i = index; content[i] != '\n' && content[i] != '\0'; i++) {
        if (content[i] == ' ' && content[i + 1] != ' ' && content[i + 1] != '\n') {
            nb_words++;
        }
    }
    nb_words++;
    buf = malloc(sizeof(char *) * (nb_words + 1));
    if (!buf) {
        return NULL;
    }
    buf[nb_words] = NULL;

    size_t i = index, j = index, k = 0;

    for (; content[i] != '\n' && content[i] != '\0'; i++) {
        if (content[i] == ' ' && content[i + 1] != ' ' && content[i + 1] != '\n') {
            buf[k] = malloc(sizeof(char) * (i - j + 1));
            if (!buf[k]) {
                return NULL;
            }
            memset(buf[k], 0, sizeof(char) * (i - j + 1));
            strncpy(buf[k], content + j, i - j);
            buf[k] = trim(buf[k]);
            buf[k] = buf[k][0] == '\0' ? NULL : buf[k];
            j = i + 1;
            k++;
        }
    }
    buf[k] = malloc(sizeof(char) * (i - j + 1));
    if (!buf[k]) {
        return NULL;
    }
    memset(buf[k], 0, sizeof(char) * (i - j + 1));
    strncpy(buf[k], content + j, i - j);
    buf[k] = buf[k][0] == '\0' ? NULL : buf[k];
    return buf;
}

const char ***parse_content(const char *content)
{
    size_t nb_lines = count('\n', content) + 1;
    size_t nb_chars = strlen(content);
    char ***buf = NULL;

    if (nb_chars <= 2) {
        return NULL;
    }
    if (content[nb_chars] == '\0' && content[nb_chars - 1] == '\n') {
        nb_lines--;
    }
    buf = malloc(sizeof(char **) * (nb_lines + 1));
    if (!buf) {
        return NULL;
    }
    buf[nb_lines] = NULL;
    for (size_t i = 0; i < nb_lines; i++) {
        buf[i] = create_line(content, i);
    }
    return (const char ***)buf;
}
