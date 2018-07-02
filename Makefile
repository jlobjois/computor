# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/24 17:39:45 by jlobjois          #+#    #+#              #
#    Updated: 2017/09/24 17:39:51 by jlobjois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Computor

PATH_SRC = ./src/

PATH_HEAD = ./include/

HEADER_FILE =	computor.h		\

SRC_FILE =	main.c		parser.c		ft_atof.c	\
			ft_sqrt.c	calcul.c		fin.c		\
			autre.c		normeparser.c\

SRC = $(SRC_FILE:%c=$(PATH_SRC)%c)

INCLUDE = $(HEADER_FILE:%h=$(PATH_HEAD)%h)

OBJ = $(SRC_FILE:.c=.o)

OBJ2 = $(OBJ:%.o=$(PATH_SRC)%.o)

HEAD_DIR = -I ./include -I ./libft

LIB = -L ./libft -lft

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	make -C ./libft/
	gcc $(FLAGS) $(HEAD_DIR) -c $(SRC)
	mv $(OBJ) $(PATH_SRC)
	gcc -o $(NAME) $(OBJ2) $(HEAD_DIR) $(LIB) $(FLAGS)

debug: $(SRC) $(INCLUDE)
	make debug -C ./libft/
	gcc $(FLAGS) $(HEAD_DIR) -c $(SRC)
	mv $(OBJ) $(PATH_SRC)
	gcc -o $(NAME) $(OBJ2) $(HEAD_DIR) $(LIB)

clean:
	make clean -C ./libft/
	rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all
