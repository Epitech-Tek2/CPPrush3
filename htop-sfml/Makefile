##
## EPITECH PROJECT, 2021
## B-CPP-300-STG-3-1-CPPrush3-maxime.owaller
## File description:
## Makefile
##

CC	=	g++
CXXFLAGS	=	-std=c++14 -Wall -Wextra -Iincludes/class -g -lsfml-window -lsfml-graphics -lsfml-audio \
                                        -lsfml-system

## ========================================================================== ##
PATH_MAIN               		=     	sources/
SRC_MAIN                		=		Run.cpp	\

## ========================================================================== ##
PATH_GAME_MANAGER               =		sources/gameManager/
SRC_GAME_MANAGER                =		Itop.cpp	\
										WindowManager.cpp	\
										Shortcuts.cpp

## ========================================================================== ##
PATH_GAME_DRAWS               	=       sources/draws/
SRC_GAME_DRAWS                	=		RectShape.cpp	\
										TableRectShape.cpp	\
										Text.cpp	\
										TitleSection.cpp	\
										ProcessGraph.cpp

SRC		=				main.cpp	\
						$(addprefix $(PATH_MAIN), $(SRC_MAIN))	\
						$(addprefix $(PATH_GAME_MANAGER), $(SRC_GAME_MANAGER)) \
						$(addprefix $(PATH_GAME_DRAWS), $(SRC_GAME_DRAWS))

OBJ		=		$(SRC:.cpp=.o)
EXEC	=		test

all:    $(EXEC)

$(EXEC):		$(OBJ)
		$(CC) $(CXXFLAGS) -o $@ $(OBJ)

tests_run:
		g++  $(OBJ) tests/*.cpp -o unit_tests --coverage -lcriterion -Iincludes/
		- ./unit_tests

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(EXEC)

re:		fclean all

.PHONY: clean fclean re all