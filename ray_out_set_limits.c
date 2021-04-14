/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_out_set_limits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:57:22 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:57:24 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_out_set_limits(t_game *game, t_ray *ray)
{
	ray->out.line_height = (int)(game->img.height / ray->perp_wall_dist);
	ray->out.draw_start = (-ray->out.line_height / 2) + (game->img.height / 2);
	if (ray->out.draw_start < 0)
		ray->out.draw_start = 0;
	ray->out.draw_end = (ray->out.line_height / 2) + (game->img.height / 2);
	if (ray->out.draw_end >= game->img.height)
		ray->out.draw_end = game->img.height - 1;
	if (ray->side == 0)
		ray->out.wall_x = game->player.pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		ray->out.wall_x = game->player.pos.x + ray->perp_wall_dist * ray->dir.x;
	ray->out.wall_x -= floor(ray->out.wall_x);
	ray->out.tex_x = (int)(ray->out.wall_x * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->dir.x > 0)
		ray->out.tex_x = TEX_WIDTH - ray->out.tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		ray->out.tex_x = TEX_WIDTH - ray->out.tex_x - 1;
}
