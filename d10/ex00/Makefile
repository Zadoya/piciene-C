# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 20:03:16 by jeckhard          #+#    #+#              #
#    Updated: 2019/07/16 20:15:49 by jeckhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
H_PATH = includes/
C_PATH = srcs/
FUNCTIONS = ft_putchar \
	  		ft_putstr \
	  		ft_strcmp \
	  		ft_strlen \
	  		ft_swap
OBJ = $(patsubst %, %.o, $(FUNCTIONS))
SRC = $(patsubst %, $(C_PATH)%.c, $(FUNCTIONS))
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(FLAGS) -I $(H_PATH)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
