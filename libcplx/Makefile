# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/01 15:30:23 by dchirol           #+#    #+#              #
#    Updated: 2017/06/01 15:43:07 by dchirol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libcplx.a
SRC		=	cplx_add.c \
			cplx_sub.c \
			cplx_mul.c \
			cplx_new.c

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Werror -Wextra -Wall -c $(SRC) -I ../includes
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
