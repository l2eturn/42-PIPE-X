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
NAME_B = pipex_bonus

CC = cc

CFLAGS = -g3 -fsanitize=address -Werror -Wextra -Wall

RM = rm -rf

SRCS =	src/main.c\
		src/utils.c

SRCS_B =	src_bonus/main_bonus.c\
			src_bonus/utils_bonus.c\

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

LIBFT = libft/libft.a

$(NAME) : $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_B) : $(OBJS_B) $(LIBFT)
	cc $(CFLAGS) $(OBJS_B) $(LIBFT) -o $(NAME_B)

$(LIBFT) :
	make bonus -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(LIBFT) $(NAME)

bonus : $(LIBFT) $(NAME_B)

fclean : clean
	$(RM) $(NAME) $(NAME_B)
	make fclean -C libft

clean :
	$(RM) $(OBJS) $(OBJS_B)
	make clean -C libft

re : fclean all

