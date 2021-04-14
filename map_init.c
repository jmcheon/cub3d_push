/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init          .c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:56:19 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:56:19 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_init(t_map *map)
{
	int		i;

	i = 0;
	map->size = (t_vec2i){0, 0};
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->texture[0] = NULL;
	map->map_buf = NULL;
	map->cnt = 0;
	map->player_on = 0;
	map->map_start = 0;
	map->sprite_cnt = 0;
	map->sprite = NULL;
	map->sprite_order = NULL;
	map->sprite_dist = NULL;
	while (i < 6)
		map->id[i++] = 0;
}
