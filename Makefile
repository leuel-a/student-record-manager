# -*- MakeFile -*-
# Constants
# ====================================================
CC = g++
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu++11
SRC = console.cpp readline_functions.cpp student.cpp linked_list.cpp file_storage.cpp course.cpp linked_list_course.cpp
OBJ = $(SRC:.cpp=.o)
NAME = school


# Rules
# ====================================================
.PHONY: all clean oclean fclean re

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lreadline

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean all
