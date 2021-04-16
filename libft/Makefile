# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 14:37:37 by cjung-mo          #+#    #+#              #
#    Updated: 2021/01/22 16:02:06 by cjung-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./ft_atoi.c \
	  ./ft_bzero.c \
	  ./ft_calloc.c \
	  ./ft_isalnum.c \
	  ./ft_isalpha.c \
	  ./ft_isascii.c \
	  ./ft_isdigit.c \
	  ./ft_isprint.c \
	  ./ft_itoa.c \
	  ./ft_uitoa_base.c \
	  ./ft_memccpy.c \
	  ./ft_memchr.c \
	  ./ft_memcmp.c \
	  ./ft_memcpy.c \
	  ./ft_memmove.c \
	  ./ft_memset.c \
	  ./ft_memdel.c \
	  ./ft_memdel_2dim.c \
	  ./ft_putchar_fd.c \
	  ./ft_putendl_fd.c \
	  ./ft_putnbr_fd.c \
	  ./ft_putnbr_fd.c \
	  ./ft_putstr_fd.c \
	  ./ft_split.c \
	  ./ft_strchr.c \
	  ./ft_strdup.c \
	  ./ft_strjoin.c \
	  ./ft_strjoin_splited.c \
	  ./ft_strlcat.c \
	  ./ft_strlcpy.c \
	  ./ft_strlen.c \
	  ./ft_strlen_2dim.c \
	  ./ft_strmapi.c \
	  ./ft_strncmp.c \
	  ./ft_strinchr.c \
	  ./ft_strnstr.c \
	  ./ft_strrchr.c \
	  ./ft_strtrim.c \
	  ./ft_substr.c \
	  ./ft_tolower.c \
	  ./ft_toupper.c \
	  ./get_next_line_bonus.c

BONUS_SRCS = ./ft_lstadd_back.c \
			./ft_lstadd_front.c \
			./ft_lstclear.c \
			./ft_lstdelone.c \
			./ft_lstiter.c \
			./ft_lstlast.c \
			./ft_lstmap.c \
			./ft_lstnew.c \
			./ft_lstsize.c

INCLUDE = ./

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I $(INCLUDE)
	
all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

bonus: $(OBJS) $(BONUS_OBJS) 
		ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
		ranlib $(NAME)

clean:
		/bin/rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
		/bin/rm -f libft.a

re: fclean all

.PHONY : all clean fclean re
