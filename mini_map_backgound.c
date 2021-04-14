/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_backgound.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:06:56 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:06:57 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mini_map_background(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_config.size.y * TILE_SIZE)
	{
		j = 0;
		while (j < game->map_config.size.x * TILE_SIZE)
		{
			game->img.data[game->img.width * i + j] = 0x6b6363;
			j++;
		}
		i++;
	}
}
