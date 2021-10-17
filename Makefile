##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

## ========================================================================== ##
PATH_SOURCES		=		./
SOURCES				=		Data/sources/CoreInfos.cpp						\
							Data/sources/Date.cpp							\
							Data/sources/NetInfos.cpp						\
							Data/sources/RamInfos.cpp 						\
							Data/sources/SystemInfos.cpp 					\
							Data/sources/UserInfos.cpp						\
							htop-ncurses/sources/Htop.cpp					\
							htop-ncurses/sources/Module.cpp					\
							htop-ncurses/sources/ModuleManage.cpp			\
							htop-ncurses/sources/Keys.cpp					\
							htop-sfml/sources/Run.cpp						\
							htop-sfml/sources/gameManager/WindowManager.cpp	\
							htop-sfml/sources/gameManager/Shortcuts.cpp		\
							htop-sfml/sources/draws/RectShape.cpp			\
							htop-sfml/sources/draws/ProcessGraph.cpp		\
							htop-sfml/sources/draws/TableRectShape.cpp		\
							htop-sfml/sources/draws/Text.cpp				\
							htop-sfml/sources/draws/TitleSection.cpp		\
							main.cpp
## ========================================================================== ##

SRC		= 	$(addprefix $(PATH_SOURCES), $(SOURCES))

PATH_TESTS	= 	tests/
TESTS_FILES	=	tests.cpp

TESTS		= 	$(addprefix $(PATH_TESTS), $(TESTS_FILES))

NAME	=		MyGKrellm

CXXFLAGS	=	-Wall -Wextra -Werror -lncurses -pthread -I./Data/includes/\
				-I./htop-ncurses/includes/ -I./htop-sfml/includes/\
				-I./htop-sfml/includes/class/\
				-lsfml-window -lsfml-graphics -lsfml-audio\
                -lsfml-system

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