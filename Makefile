# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/14 09:06:45 by atrombel          #+#    #+#              #
#    Updated: 2026/04/01 14:43:06 by atrombel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
SOURCE = $(wildcard $(SRC_DIR)/*.c)
OBJET = $(SOURCE:.c=.o)
NAME = so_long
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX_PATH = ./minilibx-linux
MINILIBX = $(MINILIBX_PATH)/libmlx.a
INCLUDE = -I. -I$(LIBFT_PATH) -I./$(MINILIBX_PATH) -I./include

all:$(NAME)

$(NAME):$(OBJET) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJET) $(INCLUDE) -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -lX11 -lXext -lm  -lz -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(MINILIBX):
	@make -C $(MINILIBX_PATH) all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -O3 -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean
	rm -f $(OBJET)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
