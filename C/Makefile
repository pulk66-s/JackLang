##
## CringeLang Makefile
##

CC		=	gcc

SRC		= 	src/main.c \
			src/files/read.c

CFLAGS	=	-W -Wall -Wextra -I./src

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
