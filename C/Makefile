##
## CringeLang Makefile
##

CC		=	gcc

SRC		= 	src/main.c 						\
			src/files/read.c 				\
			src/files/parsing.c				\
			src/logger/manager.c			\

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
