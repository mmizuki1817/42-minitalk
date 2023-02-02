# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 19:19:16 by mimatsub          #+#    #+#              #
#    Updated: 2023/02/01 23:14:34 by mimatsub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_SRCS = libft/ft_putnbr_fd.c libft/ft_strlen.c libft/ft_isdigit.c libft/ft_putchar_fd.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_printf/ft_printf.c libft/ft_printf/ft_printf_utils.c 
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
LIBFT_NAME = libft.a
LIB = $(LIBFT_NAME)

SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
SERVER_NAME = server

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CLIENT_NAME = client

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

$(NAME):	$(SERVER_NAME) $(CLIENT_NAME) $(LIBFT_NAME)

$(SERVER_NAME):		$(SERVER_OBJS) $(LIB)
				$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_NAME):		$(CLIENT_OBJS) $(LIB)
			    $(CC) $(CFLAGS) $^ -o $@

$(LIBFT_NAME):	$(LIBFT_OBJS)
				ar rc $(LIBFT_NAME) $(LIBFT_OBJS)

all:	$(NAME)

clean:
		$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(LIBFT_OBJS)

fclean:		clean
		$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(LIBFT_NAME)

re:		fclean all

.PHONY: all clean fclean re
