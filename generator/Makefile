##
## EPITECH PROJECT, 2022
## makefile
## File description:
## file that makes
##

SRC	=	src/generate_maze.c	\
		src/binary_tree.c	\
		src/alloc_map.c		\
		src/generator.c

OBJ =	$(SRC:%.c=$(BUILDDIR)/%.o)

MAIN = src/main.c

MAIN_OBJ =	$(MAIN:%.c=$(BUILDDIR)/%.o)

BUILDDIR = obj

NAME =	generator

CC = clang

CPPFLAGS =	-I../include/

CFLAGS = -Wall -Wextra

DEBUGFLAG = -g

TESTS = tests/test_conversions.c \
		tests/test_flags.c \
		tests/test_strings.c

TESTSFLAGS = -Iinclude/ -lcriterion --coverage

all:	$(NAME)

$(NAME):		$(OBJ) $(MAIN_OBJ)
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
		make -C lib/my/
		$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(DEBUGFLAG)

.PHONY: all clean fclean re

-include $(OBJ:.o=.d)
