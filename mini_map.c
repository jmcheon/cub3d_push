/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:07:03 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:07:04 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_line(t_game *game, t_vec2d d1, t_vec2d d2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = d2.x - d1.x;
	deltaY = d2.y - d1.y;
	if (fabs(deltaX) > fabs(deltaY))
		step = fabs(deltaX);
	else
		step = fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(d2.x - d1.x) > 0.01 || fabs(d2.y - d1.y) > 0.01)
	{
		game->img.data[(int)floor(d1.y) * game->img.width
			+ (int)floor(d1.x)] = 0xb3b3b3;
		d1.x += deltaX;
		d1.y += deltaY;
	}
}

static void	draw_horizontal_lines(t_game *game)
{
	int		i;
	t_vec2d	d1;
	t_vec2d	d2;

	i = 0;
	while (i < game->map_config.size.y)
	{
		d1.x = 0;
		d1.y = i * TILE_SIZE;
		d2.x = game->map_config.size.x * TILE_SIZE;
		d2.y = i * TILE_SIZE;
		draw_line(game, d1, d2);
		i++;
	}
}

void 	draw_lines(t_game *game)
{
	int		i;
	t_vec2d	d1;
	t_vec2d	d2;

	i = 0;
	while (i < game->map_config.size.x)
	{
		d1.x = i * TILE_SIZE;
		d1.y = 0;
		d2.x = i * TILE_SIZE;
		d2.y = game->map_config.size.y * TILE_SIZE;
		draw_line(game, d1, d2);
		i++;
	}
	draw_horizontal_lines(game);
}

static void	draw_rectangle(t_game *game, int x, int y)
{
	int		i;
	int		j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[game->img.width * (y + i) + x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_config.size.y)
	{
		j = 0;
		while (j < game->map_config.size.x)
		{
			if (game->map[i][j] > 0 )
				draw_rectangle(game, j, i);
			j++;
		}
		i++;
	}
}
