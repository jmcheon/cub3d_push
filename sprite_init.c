/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:57:45 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:57:45 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*sprite_init(t_map *map)
{
	map->sprite = (t_sprite *)malloc(sizeof(t_sprite) * (map->sprite_cnt + 1));
	if (!map->sprite)
		return (ft_strjoin("sprite array malloc error", ""));
	map->sprite_order = (int *)malloc(sizeof(int) * (map->sprite_cnt + 1));
	if (!map->sprite_order)
		return (ft_strjoin("sprite_order array malloc error", ""));
	map->sprite_dist = (double *)malloc(sizeof(double) * (map->sprite_cnt + 1));
	if (!map->sprite_dist)
		return (ft_strjoin("sprite_dist array malloc error", ""));
	return (NULL);
}
