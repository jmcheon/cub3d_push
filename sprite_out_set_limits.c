/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_out_set_limits.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:58:00 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:58:00 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_out_set_limits(t_game *game, t_ray *ray, t_player *player, int i)
{
	ray->sprite.x = game->map_config.sprite[game->map_config.sprite_order[i]].x
		- player->pos.x;
	ray->sprite.y = game->map_config.sprite[game->map_config.sprite_order[i]].y
		- player->pos.y;
	ray->inv_det = 1.0
		/ (player->plane.x * player->dir.y - player->dir.x * player->plane.y);
	ray->transform.x = ray->inv_det
		* (player->dir.y * ray->sprite.x - player->dir.x * ray->sprite.y);
	ray->transform.y = ray->inv_det
		* (-player->plane.y * ray->sprite.x + player->plane.x * ray->sprite.y);
	ray->sprite_screen_x = (int)((game->img.width / 2)
			* (1 + ray->transform.x / ray->transform.y));
	ray->s_out.height = abs((int)(game->img.height / (ray->transform.y)));
	ray->s_out.draw_start.y = -ray->s_out.height / 2 + game->img.height / 2;
}
