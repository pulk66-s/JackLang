#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "parsing.h"
#include "print.h"
#include "ast.h"
#include "logger.h"
#include "compiler/llvm.h"

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
    remove("log/ast.json");
    remove("log/cpt.json");
    remove("log/cpt_debug.log");
    remove("log/llvm_debug.log");
    for (int i = 1; i < ac; i++) {
        const char *content = read_file(av[i]);
        const char ***parsed = parse_content(content);

        if (!parsed) {
            printf("Cannot parse %s\n", av[i]);
            continue;
        }
        print_parse_content(parsed);
        logger().debug("Launching CPT...\n");

        struct result *cpt = launch_parsing(parsed);

        logger().debug("===========\n");
        logger().debug("=   CPT   =\n");
        logger().debug("===========\n");
        print_result(cpt);

        logger().debug("===========\n");
        logger().debug("Launching AST...\n");

        struct program_ast *ast = create_program_ast((struct program_cpt *)cpt->data);

        logger().debug("===========\n");
        logger().debug("=   AST   =\n");
        logger().debug("===========\n");
        print_ast_program(ast);
        logger().debug("===========\n");
        logger().debug("Launching llvm...\n");
        cl_compiler_llvm_start(ast);
    }
    return 0;
}
