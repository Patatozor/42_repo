# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 13:46:45 by rfumeron          #+#    #+#              #
#    Updated: 2018/12/21 17:44:35 by rfumeron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
# directories :
SRCDIR	= .
OBJDIR	= .
INCDIR	= includes/
CC		= clang
CFLAGS	= -Werror -Wall -Wextra -I $(INCDIR)
RM		= /bin/rm -f
# files :
SRC		= main.c parse.c fdf_coords.c
OBJ		= $(SRC:.c=.o)
# Rules :
all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ fclean && make -C libft/
	$(CC) -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft

clean:
	$(RM) $(OBJ)
	make -C libft/ fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
