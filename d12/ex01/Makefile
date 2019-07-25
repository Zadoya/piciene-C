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

NAME = ft_cat 
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) ft_putstr.c cat.c display.c write_file.c ft_strcmp.c -o $(NAME) 

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)