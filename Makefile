# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 16:55:07 by niragne           #+#    #+#              #
#    Updated: 2017/06/01 16:44:38 by dchirol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra
CFLAGSMLX	=	-lmlx -framework OpenGL -framework AppKit

LIB_PATH	=	libft
LIB			=	$(LIB_PATH)/libft.a

LIBCPL_PATH	=	libcplx
LIBCPL		=	$(LIBCPL_PATH)/libcplx.a

INC_DIR		=	includes
INCS		=	-I $(INC_DIR) -I $(LIB_PATH)

SRC_DIR		=	srcs
SRC			=	main.c mendelbrot.c

OBJ_DIR		=	obj

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(CFLAGSMLX) $(LIB) $(LIBCPL)

lib:
	make -C $(LIB_PATH)
	make -C $(LIBCPL_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	make -C $(LIB_PATH) clean
	make -C $(LIBCPL_PATH) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB)
	rm -f $(LIBCPL)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re