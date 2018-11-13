# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/17 16:02:35 by rfumeron          #+#    #+#              #
#    Updated: 2018/11/13 17:11:35 by rfumeron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a
# directories :
SRCDIR	:=	.
OBJDIR	:=	.
INCDIR	:=	includes/
CC		:=	clang
CFLAGS	:= 	-Werror -Wall -Wextra -I$(INCDIR)
RM		:=	/bin/rm -f
# Files :
SRC	:=	ft_atoi.c ft_isprint.c ft_lstmap.c ft_memcpy.c ft_putendl.c \
		ft_strcat.c ft_strdup.c ft_strlen.c ft_strnequ.c ft_strsub.c \
		ft_bzero.c ft_itoa.c ft_lstnew.c ft_memdel.c ft_putendl_fd.c \
		ft_strchr.c ft_strequ.c ft_strmap.c ft_strnew.c ft_strtrim.c \
		ft_isalnum.c ft_lstadd.c ft_memccpy.c ft_memalloc.c ft_memmove.c \
		ft_putnbr.c ft_strclr.c ft_striter.c ft_strmapi.c ft_strnstr.c \
		ft_tolower.c ft_isalpha.c ft_lstdel.c ft_memset.c ft_putnbr_fd.c \
		ft_strcmp.c ft_striteri.c ft_strncat.c ft_strrchr.c ft_toupper.c \
		ft_isascii.c ft_lstdelone.c ft_memchr.c ft_putchar.c ft_putstr.c \
		ft_strcpy.c ft_strjoin.c ft_strjoinfree.c ft_strncmp.c ft_strsplit.c \
		ft_isdigit.c ft_lstiter.c ft_memcmp.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_strdel.c ft_strlcat.c ft_strncpy.c ft_strstr.c ft_strtrimchar.c \
		ft_strrev.c ft_lstaddback.c ft_strtolower.c ft_strtoupper.c ft_pow2.c \
		ft_strcpyuntilc.c ft_strlenuntilc.c
OBJ		:=	$(SRC:.c=.o)
# Rules :
all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $^
	ranlib $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
