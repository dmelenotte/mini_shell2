##
## EPITECH PROJECT, 2022
## makefile
## File description:
## printf
##

SRC	=	main.c \
	src/built_in.c	\
	src/executables.c	\
	src/my_str_to_double_array.c	\
	src/my_putstr2.c	\
	src/error_handeling.c	\
	src/my_str_to_slash_array.c	\
	src/env_handler.c	\
	src/my_cd.c	\
	src/utils.c	\
	src/redirections.c	\
	src/my_str_to_bonus_array.c	\
	src/my_str_to_semicolon_array.c	\
	linked_list/my_put_list.c	\
	linked_list/my_print_list.c	\
	linked_list/my_get_node.c	\
	linked_list/my_delete_node.c	\

NAME =	mysh

PRINTF_NAME	=	miprontfaient
PRINTF_LIB	=	my
PRINTF_INCLUDE = $(PRINTF_NAME)/include

all:	$(NAME)

$(NAME):
	make -C $(PRINTF_NAME)
	gcc -o $(NAME) $(SRC)  -I./$(PRINTF_INCLUDE)	\
	-L./$(PRINTF_NAME) -l$(PRINTF_LIB) -g3 -ggdb3	\
	-Wall -Wextra

clean:
	rm -f *.o $(OBJ)
	make -C $(PRINTF_NAME) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_NAME) fclean

re:	fclean all
