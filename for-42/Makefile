# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 18:01:46 by slimvutt          #+#    #+#              #
#    Updated: 2025/10/17 18:01:46 by slimvutt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -g3 -Werror -Wextra -Wall -fsanitize=address

RM = rm - rf

SRCS =	src/pipex.c\



$(NAME) :
	make bonus -C libft
	cc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all
