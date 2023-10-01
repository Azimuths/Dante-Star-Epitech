##
## EPITECH PROJECT, 2022
## makefile
## File description:
## file that makes
##

CFLAGS = -Iinclude/

TESTS = tests/test_conversions.c	\
		tests/test_flags.c			\
		tests/test_strings.c

TESTSFLAGS = -Iinclude/ -lcriterion --coverage -g

all: generator solver clean

generator:
			make -C ./generator/

solver:
			make -C ./solver/

$(NAME): 	generator solver

clean:
			make clean -C ./generator/
			make clean -C ./solver/

fclean: 	clean
			make fclean -C ./generator/
			make fclean -C ./solver/

re: fclean all clean

tests_run:
		gcc -o test_crit $(TESTS) $(SRC) $(TESTSFLAGS)
		./test_crit

.PHONY: all clean fclean re tests_run generator solver
