##
## Makefile for Makefile in /home/wery_a/rendu/PushSwap/Test
##
## Made by adrien wery
## Login   <wery_a@epitech.net>
##
## Started on  Fri Dec  5 12:20:06 2014 adrien wery
## Last update Sat Dec 20 23:41:51 2014 adrien wery
##

SRC	= 	trace.c		\
	  	vision.c	\
	  	str.c		\
	  	mlx.c		\
	  	move.c		\
	  	init.c

CU_SRC =	cuda.cu	\
			main.cu

CC	= gcc

NVCC = nvcc

RM	= rm -f

# CFLAGS = -W -Wall -Werror

LFLAGS  = -L./mlx -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm -L/usr/local/cuda-7.5/lib64 -lcuda -lcudart

NAME	= wolf3d

OBJ	= $(SRC:.c=.o)
CU_OBJ	= $(CU_SRC:.cu=.o)

$(NAME): $(OBJ) cuda
	$(NVCC) $(OBJ) cuda.o main.o -o $(NAME) $(LFLAGS)

cuda:
	$(NVCC) -c $(CU_SRC)

all: $(NAME)

clean:
	$(RM) $(OBJ) cuda.o main.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
