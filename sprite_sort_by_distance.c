/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort_by_distance.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:58:07 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:58:07 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_order(t_pair *orders, int amount)
{
	int		i;
	int		j;
	t_pair	tmp;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

static void	sort_sprites(int *order, double *dist, int amount)
{
	int		i;
	t_pair	*sprites;

	i = 0;
	sprites = (t_pair *)malloc(sizeof(t_pair) * amount);
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}

void	sprite_sort_by_distance(t_map *map, t_player *player)
{
	int		i;

	i = 0;
	while (i < map->sprite_cnt)
	{
		map->sprite_order[i] = i;
		map->sprite_dist[i] = (player->pos.x - map->sprite[i].x)
			* (player->pos.x - map->sprite[i].x)
			+ (player->pos.y - map->sprite[i].y)
			* (player->pos.y - map->sprite[i].y);
		i++;
	}
	sort_sprites(map->sprite_order, map->sprite_dist, map->sprite_cnt);
}
