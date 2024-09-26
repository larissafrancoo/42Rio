# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 18:47:05 by lfranco           #+#    #+#              #
#    Updated: 2024/03/08 18:47:16 by lfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

LIBRARY = ./libft/
FT_PRINTF = ./ft_printf/

SERVER_SRC = server.c
CLIENT_SRC = client.c

all:	server client

libft:
	cd $(LIBRARY) && $(MAKE) && cp -v libft.a ../

ft_printf:
	cd $(FT_PRINTF) && $(MAKE) && cp -v libftprintf.a ../

minitalk:	all

server:	libft ft_printf
	cc $(SERVER_SRC) libft.a libftprintf.a -o $(SERVER_NAME)

client:	libft ft_printf
	cc $(CLIENT_SRC) libft.a libftprintf.a -o $(CLIENT_NAME)

clean:
	cd $(LIBRARY) && $(MAKE) clean
	cd $(FT_PRINTF) && $(MAKE) clean

fclean:	clean
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME)
	$(RM) libft.a libftprintf.a
	cd $(LIBRARY) && $(MAKE) fclean
	cd $(FT_PRINTF) && $(MAKE) fclean

re:	fclean all

.PHONY:	all clean fclean re libft ft_printf
