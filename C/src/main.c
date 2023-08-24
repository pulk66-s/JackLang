#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "grammar.h"

void packrat_launch(const char ***content)
{
    struct packrat p = {
        .cursor = 0,
        .x = 0,
        .y = 0,
        .content = content
    };

    struct result res = program(&p);

    for (size_t i = 0; i < res.size; i++) {
        struct result *r = &((struct result *) res.data)[i];

        if (r->success) {
            printf("SUCCESS: %s\n", (char *) r->data);
        } else {
            printf("FAILURE\n");
        }
    }
}

void print_parse_content(const char ***content)
{
    if (!content) {
        return;
    }
    for (size_t i = 0; content[i]; i++) {
        for (size_t j = 0; content[i][j]; j++) {
            printf("%s ", content[i][j]);
        }
        printf("\n");
    }
}

int main(int ac, char **av)
{
    if (ac == 1) {
        printf("USAGE: %s <file>\n", av[0]);
        return 1;
    }
    for (int i = 1; i < ac; i++) {
        char *content = read_file(av[i]);
        const char ***parsed = parse_content(content);

        if (!parsed) {
            printf("Cannot parse %s\n", av[i]);
            continue;
        }
        print_parse_content(parsed);
        if (content == NULL) {
            printf("Cannot read %s\n", av[i]);
            continue;
        }
        packrat_launch(parsed);
    }
    return 0;
}
