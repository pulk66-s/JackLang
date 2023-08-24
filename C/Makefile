##
## CringeLang Makefile
##

CC		=	gcc

SRC		= 	src/main.c 				\
			src/files/read.c 		\
			src/files/parsing.c		\
			src/grammar/word.c		\
			src/grammar/types.c		\
			src/grammar/default.c	\
			src/grammar/program.c	\
			src/grammar/chars.c		\
			src/grammar/expr.c		\
			src/print/expr.c		\
			src/print/packrat.c		\
			src/print/repartition.c	\
			src/print/word.c		\

CFLAGS	=	-W -Wall -Wextra -I./src -g3

OBJ		=	$(SRC:.c=.o)

NAME	=	cl

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
