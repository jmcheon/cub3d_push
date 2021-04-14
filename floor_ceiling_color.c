/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:55:19 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:55:20 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_ceiling_color(t_game *game)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < game->img.height)
	{
		x = 0;
		while (x < game->img.width)
		{
			color = game->map_config.floor_color;
			game->img.data[x + game->img.width * y] = color;
			color = game->map_config.ceiling_color;
			game->img.data[x + game->img.width
				* (game->img.height - y - 1)] = color;
			x++;
		}
		y++;
	}
}
