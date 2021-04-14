/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:57:33 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:57:34 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_texture_set(t_game *game, t_ray *ray)
{
	if (game->map[ray->map.y][ray->map.x] == 1)
	{
		if (ray->side == 0)
		{
			if (game->player.dir.x > 0)
				ray->out.tex_num = TEX_EAST;
			else
				ray->out.tex_num = TEX_WEST;
		}
		if (ray->side == 1)
		{
			if (game->player.dir.y < 0)
				ray->out.tex_num = TEX_NORTH;
			else
				ray->out.tex_num = TEX_SOUTH;
		}
	}
}
