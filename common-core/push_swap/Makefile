# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 12:01:01 by lfranco           #+#    #+#              #
#    Updated: 2024/05/01 06:10:11 by lfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

LIBRARY = ./libft/

SRCS = main.c\
       checker_input.c\
       checker_free.c\
       commands_push.c\
       commands_base.c\
       commands_r.c\
       commands_sp.c\
       stack_operations.c\
       sort_operations.c\

all:	push_swap

libft:
	cd $(LIBRARY) && $(MAKE) && cp -v libft.a ../

push_swap: libft
	cc -g $(SRCS) libft.a -o $(NAME)

clean:
	cd $(LIBRARY) && $(MAKE) clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) libft.a
	cd $(LIBRARY) && $(MAKE) fclean

re:	fclean all

.PHONY:	all clean fclean re libft
