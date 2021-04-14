/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_out_wall_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:57:28 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:57:29 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_out_wall_draw(t_game *game, t_ray *ray)
{
	int		y;
	int		color;

	y = ray->out.draw_start;
	ray->out.step = 1.0 * TEX_HEIGHT / ray->out.line_height;
	ray->out.tex_pos = (ray->out.draw_start - game->img.height / 2
			+ ray->out.line_height / 2) * ray->out.step;
	while (y < ray->out.draw_end)
	{
		ray->out.tex_y = (int)ray->out.tex_pos & (TEX_HEIGHT - 1);
		ray->out.tex_pos += ray->out.step;
		color = game->map_config.texture[ray->out.tex_num][TEX_WIDTH
			* ray->out.tex_y + ray->out.tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		if (game->mini_map == 1)
		{
			if (game->ray.x < game->map_config.size.x
				* TILE_SIZE && y < game->map_config.size.y * TILE_SIZE)
				color = 0x6b6363;
		}
		game->img.data[game->ray.x + game->img.width * y] = color;
		y++;
	}
}
