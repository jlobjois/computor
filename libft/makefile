# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 18:07:27 by jlobjois          #+#    #+#              #
#    Updated: 2017/03/03 17:35:24 by jlobjois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	ft_toupper.c\
		ft_tolower.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_memchr.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_isalnum.c\
		ft_isprint.c\
		ft_isdigit.c\
		ft_isascii.c\
		ft_isalpha.c\
		ft_strncat.c\
		ft_strnstr.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strdup.c\
		ft_strrchr.c\
		ft_strchr.c\
		ft_strcpy.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_strstr.c\
		ft_strlen.c\
		ft_atoi.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_strlcat.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_strsplit.c\
		ft_lstnew.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_printtab.c

SRCO = $(SRC:.c=.o)

all: $(NAME)
	@printf ""

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
