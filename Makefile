##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/minishell.c		\
		src/exec_prog.c		\
		src/disp_prompt.c	\
		src/disp_env.c		\
		src/manage_cd.c		\
		src/my_setenv.c		\
		src/my_exit.c		\
		src/manage_env.c	\
		src/list_args.c		\
		src/modify_path.c	\
		src/my_unsetenv.c	\
		src/add_line.c		\
		src/search_bin.c	\
		src/detect_characters.c	\
		src/check_status.c	\
		src/my_taballoc.c	\
		src/detect_link.c	\
		src/check_access.c	\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ./include

LIB	=	-L ./lib/my -lmy

NAME	=	42sh

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C ./lib/my clean
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	make -C ./lib/my fclean
	rm -f $(NAME)

re:	fclean all
	make -C ./lib/my re
