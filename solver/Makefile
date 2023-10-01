##
## EPITECH PROJECT, 2022
## makefile
## File description:
## file that makes
##

SRC =	src/main.c						\
		src/file_managing/load_file.c	\
		src/pathfinding/all_closed.c	\
		src/pathfinding/find_minimum.c	\
		src/pathfinding/value_map.c		\
		src/pathfinding/pathfinding.c	\
		src/utils/array_len.c			\

BUILDDIR = obj

OBJ =	$(SRC:%.c=$(BUILDDIR)/%.o)

NAME =	solver

CC = clang

CPPFLAGS =	-I../include/

CFLAGS = -Wall -Wextra

DEBUGFLAG = -g

TESTS = tests/test_conversions.c \
		tests/test_flags.c \
		tests/test_strings.c

TESTSFLAGS = -Iinclude/ -lcriterion --coverage

all:	$(NAME)

$(NAME):		$(OBJ)
				$(LINK.o) $^ $(LDLIBS) $(OUTPUT_OPTION)

.SECONDEXPANSION:
$(BUILDDIR)/%.o:	override CPPFLAGS += -MT $@ -MMD -MP -MF $(@:.o=.d)
$(BUILDDIR)/%.o:	%.c | $$(@D)/
					$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILDDIR)/:
					mkdir $@

$(BUILDDIR)%/:
					mkdir -p $@

.PRECIOUS:			$(BUILDDIR)/ $(BUILDDIR)%/

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: fclean all

tests_run:
		gcc -o test_crit $(TESTS) $(SRC) $(TESTSFLAGS)
		./test_crit

debug:
		$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(DEBUGFLAG)

.PHONY: all clean fclean re

-include $(OBJ:.o=.d)
