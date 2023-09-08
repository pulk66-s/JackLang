DEBUG		=	1

CC			= g++

SRC			=	src/main.cpp					\
				src/IO/File.cpp					\
				src/IO/Logger.cpp				\
				src/IO/CPT/char.cpp				\
				src/IO/CPT/number.cpp			\
				src/IO/CPT/type.cpp				\
				src/IO/CPT/variable.cpp			\
				src/IO/CPT/identifier.cpp		\
				src/IO/CPT/expr.cpp				\
				src/IO/CPT/program.cpp			\
				src/Parser/Token.cpp			\
				src/CPT/Grammar/Number.cpp		\
				src/CPT/Grammar/Program.cpp		\
				src/CPT/Grammar/Type.cpp		\
				src/CPT/Grammar/Variable.cpp	\
				src/CPT/Grammar/Identifier.cpp	\
				src/CPT/Grammar/SpecialChar.cpp	\
				src/CPT/Packrat/Parser.cpp		\
				src/CPT/Packrat/numbers.cpp		\
				src/CPT/Packrat/words.cpp		\
				src/CPT/Packrat/choice.cpp		\
				src/CPT/Packrat/characters.cpp	\

OBJ			=	$(SRC:.cpp=.o)
DEBUG_FLAGS	=	-g3 -fsanitize=address
CFLAGS		=	-W -Wall -Wextra -lLLVM -I./src
ifeq ($(DEBUG), 1)
	CFLAGS	+=	$(DEBUG_FLAGS)
endif
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
