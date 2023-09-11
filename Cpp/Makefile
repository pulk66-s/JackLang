DEBUG		=	1

CC			= 	g++

SRC			=	src/main.cpp								\
				src/IO/File.cpp								\
				src/IO/Logger.cpp							\
				src/IO/CPT/char.cpp							\
				src/IO/CPT/number.cpp						\
				src/IO/CPT/type.cpp							\
				src/IO/CPT/variable.cpp						\
				src/IO/CPT/identifier.cpp					\
				src/IO/CPT/expr.cpp							\
				src/IO/CPT/program.cpp						\
				src/IO/CPT/function.cpp						\
				src/IO/CPT/condition.cpp					\
				src/IO/CPT/keyword.cpp						\
				src/IO/AST/block.cpp						\
				src/IO/AST/functions.cpp					\
				src/IO/AST/prgm.cpp							\
				src/IO/AST/constant.cpp						\
				src/IO/AST/varDecl.cpp						\
				src/IO/AST/condition.cpp					\
				src/IO/AST/expr.cpp							\
				src/Parser/Token.cpp						\
				src/CPT/Grammar/Keyword/AKeyword.cpp		\
				src/CPT/Grammar/Number.cpp					\
				src/CPT/Grammar/Value.cpp					\
				src/CPT/Grammar/MaybeValue.cpp				\
				src/CPT/Grammar/Program.cpp					\
				src/CPT/Grammar/Type.cpp					\
				src/CPT/Grammar/VariableDecl.cpp			\
				src/CPT/Grammar/Identifier.cpp				\
				src/CPT/Grammar/SpecialChar.cpp				\
				src/CPT/Grammar/Statement.cpp				\
				src/CPT/Grammar/Function/FunctionDecl.cpp	\
				src/CPT/Grammar/Function/FunctionLines.cpp	\
				src/CPT/Grammar/Function/FunctionLine.cpp	\
				src/CPT/Grammar/Condition/Body.cpp			\
				src/CPT/Grammar/Condition/Condition.cpp		\
				src/CPT/Grammar/Condition/If.cpp			\
				src/CPT/Grammar/Condition/Else.cpp			\
				src/CPT/Grammar/Condition/ElseValue.cpp		\
				src/CPT/Grammar/Condition/MaybeElse.cpp		\
				src/CPT/Packrat/Parser.cpp					\
				src/CPT/Packrat/numbers.cpp					\
				src/CPT/Packrat/words.cpp					\
				src/CPT/Packrat/choice.cpp					\
				src/CPT/Packrat/characters.cpp				\
				src/AST/Block.cpp							\
				src/AST/FunctionDecl.cpp					\
				src/AST/Type.cpp							\
				src/AST/Program.cpp							\
				src/AST/VarDecl.cpp							\
				src/AST/Expr.cpp							\
				src/AST/Condition.cpp						\
				src/Compiler/LLVM/start.cpp					\
				src/Compiler/LLVM/Value.cpp					\
				src/Compiler/LLVM/Block.cpp					\
				src/Compiler/LLVM/VarDecl.cpp				\
				src/Compiler/LLVM/Type.cpp					\
				src/Compiler/LLVM/Constant.cpp				\
				src/Compiler/LLVM/Condition.cpp				\
				src/Compiler/LLVM/Lib/Module.cpp			\
				src/Compiler/LLVM/Lib/Value.cpp				\
				src/Compiler/LLVM/Lib/Builder.cpp			\
				src/Compiler/LLVM/Lib/Context.cpp			\
				src/Compiler/LLVM/Lib/Block.cpp				\
				src/Compiler/LLVM/Lib/Alloca.cpp			\
				src/Compiler/LLVM/Lib/Function.cpp			\
				src/Compiler/LLVM/Lib/FunctionType.cpp		\
				src/Compiler/LLVM/Lib/Constant.cpp			\
				src/Compiler/LLVM/Lib/Condition.cpp			\
				src/Compiler/LLVM/Function/Function.cpp		\
				src/Compiler/LLVM/Function/FunctionType.cpp	\


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
