/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_mapping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:57:50 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:57:50 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_mapping(t_map *map)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{	
			if (map->map_buf[(y * map->size.x) + x] == '2')
			{
				map->sprite[i] = (t_sprite){x + 0.5, y + 0.5, SPRITE_1};
				i++;
			}
			x++;
		}
		y++;
	}
}
