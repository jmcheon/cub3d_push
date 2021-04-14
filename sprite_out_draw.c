/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_out_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:57:55 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:57:55 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sprite_draw_y(t_game *game, t_ray *ray, int	i, int s)
{
	int		y;
	int		d;
	int		color;

	y = ray->s_out.draw_start.y;
	while (y < ray->s_out.draw_end.y)
	{
		d = (y) * 256 - game->img.height * 128
			+ ray->s_out.height * 128;
		ray->s_out.tex_y = ((d * TEX_HEIGHT) / ray->s_out.height) / 256;
		color = game->map_config.texture[game->map_config
			.sprite[game->map_config.sprite_order[i]]
			.texture][TEX_WIDTH * ray->s_out.tex_y + ray->s_out.tex_x];
		if ((color & 0x00FFFFFF) != 0)
			game->img.data[s + game->img.width * y] = color;
		y++;
	}
}

static void	sprite_draw_x(t_game *game, t_ray *ray, int	i)
{
	int		s;

	s = ray->s_out.draw_start.x;
	while (s < ray->s_out.draw_end.x)
	{
		ray->s_out.tex_x = (int)(256 * (s - (-ray->s_out.width / 2
						+ ray->sprite_screen_x)) * TEX_WIDTH
				/ ray->s_out.width) / 256;
		if (ray->transform.y > 0 && s > 0
			&& s < game->img.width && ray->transform.y < ray->zbuffer[s])
			sprite_draw_y(game, ray, i, s);
		s++;
	}
}

void	sprite_out_draw(t_game *game, t_ray *ray, int i)
{
	if (ray->s_out.draw_start.y < 0)
		ray->s_out.draw_start.y = 0;
	ray->s_out.draw_end.y = ray->s_out.height / 2 + game->img.height / 2;
	if (ray->s_out.draw_end.y >= game->img.height)
		ray->s_out.draw_end.y = game->img.height - 1;
	ray->s_out.width = abs((int)(game->img.height / ray->transform.y));
	ray->s_out.draw_start.x = -ray->s_out.width / 2 + ray->sprite_screen_x;
	if (ray->s_out.draw_start.x < 0)
		ray->s_out.draw_start.x = 0;
	ray->s_out.draw_end.x = ray->s_out.width / 2 + ray->sprite_screen_x;
	if (ray->s_out.draw_end.x >= game->img.width)
		ray->s_out.draw_end.x = game->img.width - 1;
	sprite_draw_x(game, ray, i);
}
