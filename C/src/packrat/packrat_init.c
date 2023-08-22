#include "packrat/packrat_init.h"
#include "packrat/default_grammar.h"
#include "packrat/grammar.h"
#include "packrat/words.h"
#include <stdio.h>

static struct packrat init_packrat_data_structure(const char *content)
{
    return (struct packrat) {
        .content = content,
        .cursor = 0
    };
}

void packrat_init(const char *content)
{
    struct packrat packrat = init_packrat_data_structure(content);
    struct packrat_result res = word(&packrat);

    if (res.success) {
        printf("%d %s\n", res.success, res.value);
    } else {
        printf("%d\n", res.success);
    }
}
