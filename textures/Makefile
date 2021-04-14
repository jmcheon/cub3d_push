NAME = cub3d.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ./draw_funcs.c \

INCLUDE = ./

CC = gcc

FLAGE = -lmlx -lXext -lX11 -lm

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC)  -c $< -o $@ $(FLAGE) -I $(INCLUDE)

all : $(NAME)

$(NAME) : $(OBJS)
		make bonus -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
#${LIBC}$(NAME)$(OBJS)
		ar rsc $(NAME) $(OBJS)
		ranlib $(NAME)

clean :
	/bin/rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
