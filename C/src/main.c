#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "parsing.h"

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
        const char ***parsed = parse_content(content);

        if (!parsed) {
            printf("Cannot parse %s\n", av[i]);
            continue;
        }
        print_parse_content(parsed);

        struct prgm_cpt *cpt = launch_parsing(parsed);
    }
    return 0;
}
