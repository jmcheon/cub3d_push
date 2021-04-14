/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_spawning_orientation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:56:50 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:56:51 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_spawning_orientation(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir = (t_vec2d){0, -1.05};
		game->player.plane = (t_vec2d){-0.66, 0};
	}
	else if (dir == 'S')
	{
		game->player.dir = (t_vec2d){0, 1.05};
		game->player.plane = (t_vec2d){0.66, 0};
	}
	else if (dir == 'E')
	{
		game->player.dir = (t_vec2d){1.05, 0};
		game->player.plane = (t_vec2d){0, -0.66};
	}
	else if (dir == 'W')
	{
		game->player.dir = (t_vec2d){-1.05, 0};
		game->player.plane = (t_vec2d){0, 0.66};
	}
}
