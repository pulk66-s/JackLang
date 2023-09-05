##
## CringeLang Makefile
##

CC			=	gcc

MAIN_SRC	=	src/main.c
SRC			= 	src/files/read.c 						\
				src/files/parsing.c						\
				src/files/write.c						\
				src/logger/manager.c					\
				src/parsing/launch.c					\
				src/parsing/manager.c					\
				src/parsing/default/char.c				\
				src/parsing/default/choice.c			\
				src/parsing/words/letters.c				\
				src/parsing/words/words.c				\
				src/parsing/words/numbers.c				\
				src/parsing/words/special_char.c		\
				src/grammar/program.c					\
				src/grammar/expr.c						\
				src/grammar/operation.c					\
				src/grammar/ret.c						\
				src/grammar/function.c					\
				src/grammar/type.c						\
				src/grammar/variables.c					\
				src/grammar/comparison.c				\
				src/grammar/condition.c					\
				src/grammar/loop.c						\
				src/print/cpt/loop.c					\
				src/print/cpt/condition.c				\
				src/print/cpt/ret.c						\
				src/print/cpt/char.c					\
				src/print/cpt/program.c					\
				src/print/cpt/repartition.c				\
				src/print/cpt/result.c					\
				src/print/cpt/expr.c					\
				src/print/cpt/operation.c				\
				src/print/cpt/numbers.c					\
				src/print/cpt/string.c					\
				src/print/cpt/function.c				\
				src/print/cpt/variables.c				\
				src/print/cpt/keyword.c					\
				src/print/cpt/comparison.c				\
				src/print/ast/constant.c				\
				src/print/ast/condition.c				\
				src/print/ast/expr.c					\
				src/print/ast/line.c					\
				src/print/ast/operation.c				\
				src/print/ast/ret.c						\
				src/print/ast/program.c					\
				src/print/ast/function.c				\
				src/print/ast/type.c					\
				src/print/ast/variables.c				\
				src/print/ast/comparison.c				\
				src/print/ast/loop.c					\
				src/ast/context/variables.c				\
				src/ast/comparison.c					\
				src/ast/type.c							\
				src/ast/loop.c							\
				src/ast/create.c						\
				src/ast/lines.c							\
				src/ast/expr.c							\
				src/ast/ret.c							\
				src/ast/operation.c						\
				src/ast/constant.c						\
				src/ast/function.c						\
				src/ast/variables.c						\
				src/ast/condition.c						\
				src/compiler/llvm/lib/module.c			\
				src/compiler/llvm/lib/function.c		\
				src/compiler/llvm/lib/block.c			\
				src/compiler/llvm/lib/builder.c			\
				src/compiler/llvm/lib/constant.c		\
				src/compiler/llvm/lib/operation.c		\
				src/compiler/llvm/lib/type.c			\
				src/compiler/llvm/lib/ret.c				\
				src/compiler/llvm/lib/variables.c		\
				src/compiler/llvm/lib/condition.c		\
				src/compiler/llvm/lib/comparison.c		\
				src/compiler/llvm/lib/jmp.c				\
				src/compiler/llvm/type.c				\
				src/compiler/llvm/variables.c			\
				src/compiler/llvm/start.c				\
				src/compiler/llvm/line.c				\
				src/compiler/llvm/constant.c			\
				src/compiler/llvm/expr.c				\
				src/compiler/llvm/operation.c			\
				src/compiler/llvm/ret.c					\
				src/compiler/llvm/function.c			\
				src/compiler/llvm/condition.c			\
				src/compiler/llvm/comparison.c			\
				src/compiler/llvm/loop.c				\
				src/compiler/llvm/context/variables.c	\

TESTS_SRC	=	$(SRC)								\
				tests/main.c						\
				tests/unit.c						\
				tests/units/categories/add.c		\
				tests/units/categories/launch.c		\
				tests/units/packrat/init.c			\
				tests/units/packrat/next.c			\
				tests/units/packrat/alpha.c			\
				tests/units/packrat/numbers.c		\
				tests/units/packrat/operation.c		\
				tests/units/tokens/create_tokens.c	\
				tests/units/asserts/char.c			\
				tests/units/asserts/null.c			\
				tests/units/asserts/int.c			\

CFLAGS		=	-W -Wall -Wextra -I./src -I./tests -g3 -lLLVM

OBJ			=	$(SRC:.c=.o) $(MAIN_SRC:.c=.o)
TESTS_OBJ	=	$(TESTS_SRC:.c=.o)

NAME		=	cl

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run_tests: clean_tests $(TESTS_OBJ)
	$(CC) $(CFLAGS) $(TESTS_OBJ) -o $@
	valgrind ./$@

clean_tests:
	$(RM) $(TESTS_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
