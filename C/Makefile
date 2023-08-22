##
## CringeLang Makefile
##

CC		=	gcc

SRC		= 	src/main.c \
			src/files/read.c \
			src/packrat/packrat_init.c \
			src/packrat/default_grammar.c \
			src/packrat/words.c \

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
