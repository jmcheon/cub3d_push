/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:56:13 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:56:13 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*map_validation_check(t_game *game, t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 1;
	if (game->map != NULL)
	{
		while (x < map->size.x)
		{
			if (game->map[0][x] != 1 || game->map[map->size.y - 1][x] != 1)
				return (ft_strjoin("invalid map", " error"));
			x++;
		}
		while (y < map->size.y - 1)
		{
			if (game->map[y][0] != 1 || game->map[y][map->size.x - 1] != 1)
				return (ft_strjoin("invalid map", " error"));
			y++;
		}
	}
	if (map->player_on != 1)
		return (ft_strjoin("error no player ", "exists"));
	return (NULL);
}

static char	*map_create_initialization(t_game *game, t_map *map)
{
	int		x;
	int		y;

	if (game->map == NULL)
	{
		y = 0;
		game->map = (int **)malloc(sizeof(int *) * (map->size.y + 1));
		if (!game->map)
			return (ft_strjoin("map width error", ft_itoa(map->size.y + 1)));
		while (y < map->size.y)
		{
			game->map[y] = (int *)malloc(sizeof(int) * (map->size.x + 1));
			if (!game->map[y++])
				return (ft_strjoin("map height error",
						ft_itoa(map->size.x + 1)));
		}
		y = -1;
		while (++y < map->size.y)
		{
			x = 0;
			while (x < map->size.x)
				game->map[y][x++] = 0;
		}
	}
	return (NULL);
}

static char	*i_map_create(t_game *game, t_map *map, int x, int y)
{
	if (map->map_buf[(y * map->size.x) + x] == '0')
		game->map[y][x] = 0;
	else if (map->map_buf[(y * map->size.x) + x] == '1')
		game->map[y][x] = 1;
	else if (map->map_buf[(y * map->size.x) + x] == '2')
	{
		game->map[y][x] = 0;
		sprite_mapping(map);
	}
	else if (ft_strinchr("NESW", map->map_buf[(y * map->size.x) + x]))
	{
		if (map->player_on == 1)
			return (ft_strjoin("error already player ", "exists"));
		game->map[y][x] = 0;
		game->player.pos = (t_vec2d)
		{(double)(x + x + 1) / 2, (double)(y + y + 1) / 2};
		player_spawning_orientation(game, map->map_buf[(y * map->size.x) + x]);
		map->player_on = 1;
	}
	else
		return (ft_strjoin("invalied character in ", "map"));
	return (NULL);
}

char	*map_create(t_game *game, t_map *map)
{
	int		x;
	int		y;
	char	*ret;

	y = 0;
	if (map->map_start == 0)
		return (ft_strjoin("no map info ", "error"));
	sprite_compute(map);
	ret = map_create_initialization(game, map);
	ret = sprite_init(map);
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			ret = i_map_create(game, &game->map_config, x, y);
			if (ret != NULL)
				return (ret);
			x++;
		}
		y++;
	}
	ret = map_validation_check(game, &game->map_config);
	return (ret);
}
