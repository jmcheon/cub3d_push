# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 14:06:35 by cjung-mo          #+#    #+#              #
#    Updated: 2021/04/14 14:06:36 by cjung-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ./draw_rays.c \
	   ./error_exit.c \
	   ./game_close.c \
	   ./game_engine_init.c \
	   ./game_update_window.c \
	   ./image_clear.c \
	   ./image_init.c \
	   ./bmp.c \
	   ./export_bmp.c \
	   ./map_load.c \
	   ./map_init.c \
	   ./map_parse_line.c \
	   ./id_parse_texture.c \
	   ./id_parse_color.c \
	   ./id_parse_resolution.c \
	   ./decimal_string_validation_check.c \
	   ./map_create.c \
	   ./map_parse_config.c \
	   ./floor_ceiling_color.c \
	   ./sprite_init.c \
	   ./sprite_mapping.c \
	   ./sprite_compute.c \
	   ./player_spawning_orientation.c \
	   ./player_init.c \
	   ./key_press.c \
	   ./mouse_press.c \
	   ./ray_init.c \
	   ./ray_find_side.c \
	   ./ray_compute_dda.c \
	   ./ray_compute_distance.c \
	   ./ray_out_set_limits.c \
	   ./ray_texture_set.c \
	   ./ray_out_wall_draw.c \
	   ./ray_compute.c \
	   ./sprite_sort_by_distance.c \
	   ./sprite_out_draw.c \
	   ./sprite_out_set_limits.c \
	   ./load_image.c \
	   ./image_data_load.c \
	   ./mini_map.c \
	   ./mini_map_backgound.c \
	   ./main.c \

INCLUDE =  -I./ -Imlx/ -Ilibft/

CC		= gcc

FLAGE	= -g -Wall -Werror -Wextra
LXFLAGE	= -lmlx -lXext -lX11 -lm

MLX = -L./mlx
	  
OBJS = $(SRCS:.c=.o)

#%.o : %.c
#	$(CC)  -c $< -o $@ $(FLAGE) $(LXFLAGE) $(MLX) $(INCLUDE)

all : $(NAME)

$(NAME) : $(MLX) $(OBJS)
		make bonus -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_LIB) $(LIBFT_LIB)
		$(CC) $(OBJS) $(LXFLAGE) $(FLAGE) -o $(NAME) $(MLX) $(INCLUDE) $(LIBFT_LIB) 

$(MLX) :
	make -C mlx

bonus : all

clean :
	/bin/rm -f $(OBJS)
	make clean -C $(LIBFT)
	make clean -C mlx

fclean : clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

norm :
	norminette *.[ch]

.PHONY : all clean fclean re bonus norm
