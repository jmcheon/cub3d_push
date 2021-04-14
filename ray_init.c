/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:57:16 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:57:17 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_game *game, t_ray *ray, t_player *player)
{
	ray->camera_x = 2 * ray->x / (double)(game->img.width) - 1;
	ray->dir.x = player->dir.x + (player->plane.x * ray->camera_x);
	ray->dir.y = player->dir.y + (player->plane.y * ray->camera_x);
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	ray->delta.x = sqrt(1
			+ (ray->dir.y * ray->dir.y) / (ray->dir.x * ray->dir.x));
	ray->delta.y = sqrt(1
			+ (ray->dir.x * ray->dir.x) / (ray->dir.y * ray->dir.y));
	ray->hit = 0;
}
