# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 16:10:17 by abellakr          #+#    #+#              #
#    Updated: 2022/02/27 13:06:24 by abellakr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = fdf

CC = gcc

CFlAGS = -Wall -Wextra -Werror

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit

SRC = fdf.c read_maps.c utils.c draw_map.c graphic.c check_all.c free_leaks.c \
	math_handling.c
B_SRC = fdf_bonus.c read_maps_bonus.c utils_bonus.c draw_map_bonus.c graphic_bonus.c check_all_bonus.c free_leaks_bonus.c \
	math_handling_bonus.c mlx_hooks_bonus.c rotation_bonus.c mlx_hooks_bonus2.c
OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo " \
			──────────────────────────────────────────────\n\
			─██████████████─████████████───██████████████─\n\
			─██░░░░░░░░░░██─██░░░░░░░░████─██░░░░░░░░░░██─\n\
			─██░░██████████─██░░████░░░░██─██░░██████████─\n\
			─██░░██─────────██░░██──██░░██─██░░██─────────\n\
			─██░░██████████─██░░██──██░░██─██░░██████████─\n\
			─██░░░░░░░░░░██─██░░██──██░░██─██░░░░░░░░░░██─\n\
			─██░░██████████─██░░██──██░░██─██░░██████████─\n\
			─██░░██─────────██░░██──██░░██─██░░██─────────\n\
			─██░░██─────────██░░████░░░░██─██░░██─────────\n\
			─██░░██─────────██░░░░░░░░████─██░░██─────────\n\
			─██████─────────████████████───██████─────────\n\
			────────────────────────────────────────────── \n"
	@rm -rf $(B_OBJ) $(NAME)
	@make -C ./libft
	@$(CC) $(CFlAGS) $(FRAMEWORKS) $(OBJ) ./libft/libft.a -o $(NAME) 
	
bonus : $(B_OBJ)
	@echo " \
			──────────────────────────────────────────────\n\
			─██████████████─████████████───██████████████─\n\
			─██░░░░░░░░░░██─██░░░░░░░░████─██░░░░░░░░░░██─\n\
			─██░░██████████─██░░████░░░░██─██░░██████████─\n\
			─██░░██─────────██░░██──██░░██─██░░██─────────\n\
			─██░░██████████─██░░██──██░░██─██░░██████████─\n\
			─██░░░░░░░░░░██─██░░██──██░░██─██░░░░░░░░░░██─\n\
			─██░░██████████─██░░██──██░░██─██░░██████████─\n\
			─██░░██─────────██░░██──██░░██─██░░██─────────\n\
			─██░░██─────────██░░████░░░░██─██░░██─────────\n\
			─██░░██─────────██░░░░░░░░████─██░░██─────────\n\
			─██████─────────████████████───██████─────────\n\
			────────────────────────────────────────────── \n"
	@rm -rf $(OBJ) $(NAME)
	@make -C ./libft
	@$(CC) $(CFlAGS) $(FRAMEWORKS) $(B_SRC) ./libft/libft.a -o $(NAME) -g
	
fclean : clean

	@rm -rf $(NAME)
	@make fclean -C ./libft
clean :
	@rm -rf $(OBJ)
	@rm -rf $(B_OBJ)
	@make clean -C ./libft
	
re : fclean all 
	
.PHONY : clean fclean all re
