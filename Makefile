##
## EPITECH PROJECT, 2021
## makefile
## File description:
## compile all program
##

IFLAG   =       -I ./includes

SRC	=	error.c	\
		player_handeling.c	\
		end_test.c	\
		display.c	\
		equal_tests.c	\
		free.c	\
		fs_read.c	\
		my_sokoban.c	\
		lib/my/my_putstr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_strlen.c	\
		my_str_to_word_array.c	\
		suppr.c	\
		my_strcpy.c	\
		pop_tab.c	\
		map_handeling.c	\
		display_usage.c	\
		restart.c

OBJ = $(SRC:.c=.o)

CFLAGS	=	-W -Werror -Wextra -Wall -lncurses $(IFLAG)

TFLAG	=	-lcriterion --coverage

NAME	=	my_sokoban

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAG) -g -g3

clean:
	rm -f *~

fclean:	clean
	rm -f $(NAME)	\
	rm -f *.gcno	\
	rm -f *.gcda	\
	rm -f *.o

val:
	gcc -o $(NAME) -I ./includes/ main.c $(SRC) $(IFLAG) $(CFLAG) -g -g3

tests_run:
	gcc -o unit_test $(MFLAG) -I ./includes/ $(SRC) $(CFLAG) $(TFLAG)
	./unit_test

re: fclean all
