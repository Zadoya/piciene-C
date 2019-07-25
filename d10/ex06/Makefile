# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 14:23:07 by jeckhard          #+#    #+#              #
#    Updated: 2019/07/16 20:32:35 by jeckhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean

all: $(NAME)

$(NAME):
	@gcc main.c $(FLAGS) -L. -lft -o $(NAME)

clean:
	@rm -f $(NAME)
