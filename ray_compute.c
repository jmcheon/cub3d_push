/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:57:07 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:57:07 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_compute(t_game *game)
{
	ray_init(game, &game->ray, &game->player);
	ray_find_side(game, &game->ray, &game->player);
	ray_compute_dda(game, &game->ray, &game->player);
	if (game->mini_map == 1)
		draw_ray_lines(&game->img, &game->pp, &game->pd, game->ray.color);
	ray_compute_distance(game, &game->ray);
	ray_out_set_limits(game, &game->ray);
	ray_texture_set(game, &game->ray);
	ray_out_wall_draw(game, &game->ray);
	game->ray.zbuffer[game->ray.x] = game->ray.perp_wall_dist;
}
