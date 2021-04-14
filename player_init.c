/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:07:17 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:07:17 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_game *game)
{
	game->player.pos = (t_vec2d){2, 2};
	game->player.dir = (t_vec2d){-1, 0};
	game->player.plane = (t_vec2d){0, 0.66};
	game->player.move_sp = 0.05;
	game->player.rot_sp = 0.05;
}
