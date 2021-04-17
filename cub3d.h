/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:04:28 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:04:29 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "key_linux.h"
# include "./libft/libft.h"
# include "./libft/get_next_line_bonus.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_MOUSE_PRESS		4
# define X_EVENT_MOUSE_RELEASE		5
# define X_EVENT_MOUSE_MOVE			6
# define X_EVENT_KEY_EXIT				17
# define X_EVENT_DESTROY_NOTIFY 33 

# define P_RESOLUTION "R"
# define P_TEX_NORTH "NO"
# define P_TEX_SOUTH "SO"
# define P_TEX_WEST "WE"
# define P_TEX_EAST "EA"
# define P_SPRITE "S"
# define P_FLOOR_COLOR "F"
# define P_CEILING_COLOR "C"
# define P_EXTENTION ".cub"
# define SPRITE_1 4
# define TEX_NORTH 0
# define TEX_SOUTH 1
# define TEX_WEST 2
# define TEX_EAST 3
# define EXPORT_FILE "cub3d.bmp"
# define WINDOW_NAME "cub3d"

# define TILE_SIZE 16 
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;

typedef struct s_pair
{
	double	first;
	int		second;
}					t_pair;

typedef struct s_vec2d
{
	double	x;
	double	y;
}				t_vec2d;

typedef struct s_vec2i
{
	int		x;
	int		y;
}				t_vec2i;

typedef struct s_player
{
	t_vec2d	pos;
	t_vec2d	dir;
	t_vec2d	plane;
	double	move_sp;
	double	rot_sp;
	int		color;
}				t_player;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_ray_out
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;

}			t_ray_out;

typedef struct s_ray_out_sprite
{
	int		height;
	int		width;
	t_vec2i	draw_start;
	t_vec2i	draw_end;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
}			t_ray_out_sprite;

typedef struct s_ray
{
	int					x;
	int					side;
	int					hit;
	int					color;
	t_vec2d				pos;
	t_vec2d				dir;
	t_vec2d				delta;
	t_vec2i				map;
	t_vec2d				step;
	t_vec2d				side_dist;
	t_player			*player;
	double				camera_x;
	double				perp_wall_dist;
	t_vec2d				sprite;
	double				inv_det;
	t_vec2d				transform;
	int					sprite_screen_x;
	t_ray_out			out;
	t_ray_out_sprite	s_out;
	double				*zbuffer;
}				t_ray;

typedef struct s_map
{
	t_vec2i		size;
	int			floor_color;
	int			ceiling_color;
	int			*texture[6];
	int			id[6];
	char		*map_buf;
	int			player_on;
	int			cnt;
	int			map_start;
	int			sprite_cnt;
	t_sprite	*sprite;
	int			*sprite_order;
	double		*sprite_dist;

}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			mini_map;
	int			save_arg;
	t_img		img;
	t_ray		ray;
	t_map		map_config;
	t_player	player;
	t_vec2d		pp;
	t_vec2d		pd;
	int			**map;
}				t_game;

int		draw_ray_lines(t_img *img, t_vec2d *start, t_vec2d *end, int color);
int		save_bmp(t_game *game);
int		engine_loop(t_game *game);
int		export_bmp(t_game *game);
void	error_exit(char *error);
void	game_engine_init(int save_arg, char *path);
void	game_update_window(t_game *game);
int		game_close(t_game *game);
void	image_clear(t_game *game);
void	image_init(t_img *img);

void	map_init(t_map *map);
void	map_load(t_game *game, char *path);
char	*map_parse_line(t_game *game, char *line);
char	*map_parse_config(t_game *game, t_map *map, char **splited);
char	*map_create(t_game *game, t_map *map);

char	*id_parse_texture(t_game *game, char **path, int flag);
char	*id_parse_color(t_game *game, char **str);
char	*id_parse_resolution(t_game *game, char **str);
char	*decimal_string_validation_check(char **str);

void	floor_ceiling_color(t_game *game);

char	*sprite_init(t_map *map);
void	sprite_mapping(t_map *map);
void	sprite_compute(t_map *map);
void	player_spawning_orientation(t_game *game, char dir);
void	player_init(t_game *game);
int		key_press(int key, t_game *game);
int		mouse_press(t_game *game);

void	ray_init(t_game *game, t_ray *ray, t_player *player);
void	ray_find_side(t_game *game, t_ray *ray, t_player *player);
void	ray_compute_dda(t_game *game, t_ray *ray, t_player *player);
void	ray_compute_distance(t_game *game, t_ray *ray);
void	ray_out_set_limits(t_game *game, t_ray *ray);
void	ray_texture_set(t_game *game, t_ray *ray);
void	ray_out_wall_draw(t_game *game, t_ray *ray);
void	ray_compute(t_game *game);

void	sprite_sort_by_distance(t_map *map, t_player *player);
void	sprite_out_draw(t_game *game, t_ray *ray, int i);
void	sprite_out_set_limits(t_game *game,
			t_ray *ray, t_player *player, int i);

void	draw_rectangles(t_game *game);
void	draw_lines(t_game *game);
void	mini_map_background(t_game *game);
void	load_image(t_game *game, int *texture, char *path, t_img *img);
void	image_data_load(t_game *game);
#endif
