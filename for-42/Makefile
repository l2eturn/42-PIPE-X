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

CFLAGS = -g3 -fsanitize=address -Werror -Wextra -Wall

RM = rm -rf

SRCS =	src/main.c\
		src/utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

$(NAME) : $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make bonus -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(LIBFT) $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(OBJS)
	make clean -C libft

re : fclean all

