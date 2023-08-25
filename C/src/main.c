#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "grammar.h"
#include "print.h"

void packrat_launch(const char ***content)
{
    struct packrat p = {
        .cursor = 0,
        .x = 0,
        .y = 0,
        .content = content
    };
    struct result res = program(&p);

    print_packrat(&res);
}

void print_parse_content(const char ***content)
{
    if (!content) {
        return;
    }
    for (size_t i = 0; content[i]; i++) {
        printf("Line %ld: ", i);
        for (size_t j = 0; content[i][j]; j++) {
            printf("(%s) ", content[i][j]);
        }
        printf("\n");
    }
    printf("======\n");
}

int main(int ac, char **av)
{
    if (ac == 1) {
        printf("USAGE: %s <file>\n", av[0]);
        return 1;
    }
    for (int i = 1; i < ac; i++) {
        const char *content = read_file(av[i]);
        printf("content: %s\n", content);
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
