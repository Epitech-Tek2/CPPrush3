##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

## ========================================================================== ##
PATH_SOURCES		=		sources/
SOURCES				=		Htop.cpp			\
							Module.cpp			\
							ModuleManage.cpp	\
							Keys.cpp

## ========================================================================== ##
PATH_ROOT			=		./
ROOT				=		main.cpp

SRC		= 	$(addprefix $(PATH_SOURCES), $(SOURCES))		\
			$(addprefix $(PATH_ROOT), $(ROOT))

PATH_TESTS	= 	tests/
TESTS_FILES	=	tests.cpp

TESTS		= 	$(addprefix $(PATH_TESTS), $(TESTS_FILES))

NAME	=		htop-ncurses

CXXFLAGS	=	-Wall -Wextra -Werror -lncurses -Iincludes/

OBJ		=		$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
		@g++ -o $(NAME) $(OBJ) $(CXXFLAGS)
		@echo -e "\033[01;38;5;10m================Compiling: Done\033[0;0m"

all:	$(NAME)

.PHONY:	clean

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)
		@rm -f vgcore*
		@rm -f *.gcda
		@rm -f *.gcno
		@rm -f unit_tests

re: fclean all

debug:
	@g++ -o $(NAME) $(SRC) $(CXXFLAGS) $(DEBUG) -g
	@echo -e "\033[01;38;5;45m============Valgrind compilation: Done\033[0;0m"

tests_run:
	g++ -o unit_tests $(SRC) $(TESTS) --coverage -lcriterion
	- ./unit_tests

gcovr:
	gcovr --exclude ./tests