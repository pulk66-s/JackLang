#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "packrat.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        printf("USAGE: %s <file>\n", av[0]);
        return 1;
    }
    for (int i = 1; i < ac; i++) {
        char *content = read_file(av[i]);
        if (content == NULL) {
            printf("Cannot read %s\n", av[i]);
            continue;
        }
        packrat_init(content);
        free(content);
    }
    return 0;
}