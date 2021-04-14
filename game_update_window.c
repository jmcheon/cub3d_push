/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:05:32 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:05:33 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_update_window(t_game *game)
{
	int		i;

	i = 0;
	floor_ceiling_color(game);
	game->ray.x = 0;
	if (game->mini_map == 1)
		mini_map_background(game);
	while (game->ray.x < game->img.width)
	{
		ray_compute(game);
		game->ray.x++;
	}
	sprite_sort_by_distance(&game->map_config, &game->player);
	while (i < game->map_config.sprite_cnt)
	{
		sprite_out_set_limits(game, &game->ray, &game->player, i);
		sprite_out_draw(game, &game->ray, i);
		i++;
	}
}
