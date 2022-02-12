# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 19:21:12 by abellakr          #+#    #+#              #
#    Updated: 2021/12/09 00:38:10 by abellakr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c ft_memcmp.c ft_strdup.c ft_strnstr.c \
		ft_atoi.c ft_isascii.c ft_memcpy.c ft_strlcat.c	ft_strrchr.c \
		ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c \
		ft_calloc.c	ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c \
		ft_isalnum.c ft_memchr.c ft_strchr.c ft_strncmp.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_split.c 
		
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c
		
OBJECT = $(SRC:.c=.o)
BONUS_O = $(BONUS:.c=.o)
CC = cc
CFlAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT)
	ar rc $(NAME) $(OBJECT)
bonus : $(BONUS_O) $(OBJECT)
	ar rc $(NAME) $(BONUS_O) $(OBJECT)
 
clean :
	rm -f $(OBJECT) $(BONUS_O)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : clean fclean all re bonus
