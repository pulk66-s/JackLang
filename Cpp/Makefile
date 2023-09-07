CC			= g++

SRC			=	src/main.cpp				\
				src/IO/File.cpp				\
				src/IO/Logger.cpp			\
				src/Parser/Token.cpp		\
				src/CPT/Grammar/Number.cpp	\
				src/CPT/Grammar/Program.cpp	\
				src/CPT/Packrat/Parser.cpp	\
				src/CPT/Packrat/numbers.cpp	\

OBJ			=	$(SRC:.cpp=.o)
CFLAGS		=	-W -Wall -Wextra -lLLVM -I./src 
NAME		=	cl

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
