# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 18:13:59 by abellakr          #+#    #+#              #
#    Updated: 2022/02/11 23:15:25 by abellakr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFlAGS = -Wall -Wextra -Werror

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit

SRC = main.c read_maps.c utils.c draw_map.c

all : $(NAME)

$(NAME) :
	make -C ./libft 
	$(CC) $(CFlAGS) $(FRAMEWORKS) $(SRC) ./libft/libft.a -o $(NAME) -g 
clean :
	rm -rf $(NAME) 
	make clean -C ./libft
fclean : clean
	make fclean -C ./libft
re : fclean all 
	
.PHONY : clean fclean all re
