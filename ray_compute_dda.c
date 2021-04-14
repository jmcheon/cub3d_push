/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_compute_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:56:55 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:56:56 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_compute_raycasts_side_y(t_game *game, t_ray *ray,
															t_player *player)
{
	if (ray->dir.x < 0 && ray->dir.y < 0)
		game->pd.y = (player->pos.y - sqrt(ray->side_dist.x * ray->side_dist.x
					- (ray->map.x - player->pos.x)
					* (ray->map.x - player->pos.x))) * TILE_SIZE;
	else if (ray->dir.x < 0 && ray->dir.y > 0)
		game->pd.y = (player->pos.y + sqrt(ray->side_dist.x * ray->side_dist.x
					- (ray->map.x - player->pos.x)
					* (ray->map.x - player->pos.x))) * TILE_SIZE;
	game->pd.x = ray->map.x * TILE_SIZE;
	if (ray->dir.x > 0 && ray->dir.y < 0)
	{
		game->pd.y = (player->pos.y - sqrt(ray->side_dist.x * ray->side_dist.x
					- (ray->map.x + 1.0 - player->pos.x)
					* (ray->map.x + 1.0 - player->pos.x))) * TILE_SIZE;
		game->pd.x = (ray->map.x + 1.0) * TILE_SIZE;
	}
	else if (ray->dir.x > 0 && ray->dir.y > 0)
	{
		game->pd.y = (player->pos.y + sqrt(ray->side_dist.x * ray->side_dist.x
					- (ray->map.x + 1.0 - player->pos.x)
					* (ray->map.x + 1.0 - player->pos.x))) * TILE_SIZE;
		game->pd.x = (ray->map.x + 1.0) * TILE_SIZE;
	}
}

static void	ray_compute_raycasts_side_x(t_game *game, t_ray *ray,
															t_player *player)
{
	if (ray->dir.x < 0 && ray->dir.y < 0)
		game->pd.x = (player->pos.x - sqrt(ray->side_dist.y * ray->side_dist.y
					- (player->pos.y - ray->map.y)
					* (player->pos.y - ray->map.y))) * TILE_SIZE;
	else if (ray->dir.x > 0 && ray->dir.y < 0)
		game->pd.x = (player->pos.x + sqrt(ray->side_dist.y * ray->side_dist.y
					- (ray->map.y - player->pos.y)
					* (ray->map.y - player->pos.y))) * TILE_SIZE;
	game->pd.y = ray->map.y * TILE_SIZE;
	if (ray->dir.x < 0 && ray->dir.y > 0)
	{
		game->pd.x = (player->pos.x - sqrt(ray->side_dist.y * ray->side_dist.y
					- (ray->map.y + 1.0 - player->pos.y)
					* (ray->map.y + 1.0 - player->pos.y))) * TILE_SIZE;
		game->pd.y = (ray->map.y + 1.0) * TILE_SIZE;
	}
	else if (ray->dir.x > 0 && ray->dir.y > 0)
	{
		game->pd.x = (player->pos.x + sqrt(ray->side_dist.y * ray->side_dist.y
					- (ray->map.y + 1.0 - player->pos.y)
					* (ray->map.y + 1.0 - player->pos.y))) * TILE_SIZE;
		game->pd.y = (ray->map.y + 1.0) * TILE_SIZE;
	}
}

void	ray_compute_dda(t_game *game, t_ray *ray, t_player *player)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray_compute_raycasts_side_y(game, ray, player);
			ray->color = 0x00ff00;
			ray->side_dist.x += ray->delta.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray_compute_raycasts_side_x(game, ray, player);
			ray->color = 0xff0000;
			ray->side_dist.y += ray->delta.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (game->map[ray->map.y][ray->map.x] > 0)
			ray->hit = 1;
	}
}
