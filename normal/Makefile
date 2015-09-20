##
## Makefile for Makefile in /home/wery_a/rendu/PushSwap/Test
##
## Made by adrien wery
## Login   <wery_a@epitech.net>
##
## Started on  Fri Dec  5 12:20:06 2014 adrien wery
## Last update Sat Dec 20 23:41:51 2014 adrien wery
##

SRC	= main.c	\
	  trace.c	\
	  vision.c	\
	  str.c		\
	  mlx.c		\
	  move.c	\
	  init.c

CC	= gcc -g

RM	= rm -f

CFLAGS = -W -Wall -Werror

LFLAGS  = -L./mlx -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm

NAME	= wolf3d

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
