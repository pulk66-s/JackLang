##
## CringeLang Makefile
##

CC			=	gcc

MAIN_SRC	=	src/main.c
SRC			= 	src/files/read.c 					\
				src/files/parsing.c					\
				src/logger/manager.c				\
				src/parsing/launch.c				\
				src/parsing/manager.c				\
				src/parsing/default/char.c			\
				src/parsing/default/choice.c		\
				src/parsing/words/letters.c			\
				src/parsing/words/words.c			\
				src/parsing/words/numbers.c			\
				src/parsing/words/special_char.c	\
				src/grammar/program.c				\
				src/grammar/expr.c					\
				src/grammar/operation.c				\
				src/grammar/ret.c					\
				src/print/ret.c						\
				src/print/char.c					\
				src/print/program.c					\
				src/print/repartition.c				\
				src/print/result.c					\
				src/print/expr.c					\
				src/print/operation.c				\
				src/print/numbers.c					\
				src/print/string.c					\
				src/ast/create.c					\
				src/ast/lines.c						\
				src/ast/expr.c						\
				src/compiler/llvm/lib/module.c		\
				src/compiler/llvm/lib/function.c	\
				src/compiler/llvm/lib/block.c		\
				src/compiler/llvm/lib/builder.c		\
				src/compiler/llvm/lib/constant.c	\
				src/compiler/llvm/lib/operation.c	\
				src/compiler/llvm/start.c			\

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
