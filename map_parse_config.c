/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:56:35 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:56:35 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*i_malloc_map_buf(t_map *map, char *line, char **str)
{
	if (map->map_buf != NULL)
	{
		*str = (char *)malloc(sizeof(char) * (ft_strlen(map->map_buf) + 1));
		if (!*str)
			return (ft_strjoin("map buf error", ""));
		ft_strlcpy(*str, map->map_buf, ft_strlen(map->map_buf) + 1);
		ft_memdel(&map->map_buf);
	}
	else if (map->map_buf == NULL)
	{
		*str = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!*str)
			return (ft_strjoin("map buf error", ""));
		ft_strlcpy(*str, line, ft_strlen(line) + 1);
	}
	if (map->map_buf == NULL)
	{
		map->map_buf = (char *)malloc(sizeof(char)
				* (map->size.x * map->size.y + 1));
		if (!map->map_buf)
			return (ft_strjoin("map buf error", ""));
	}
	ft_strlcpy(map->map_buf, *str, map->size.x * map->size.y + 1);
	return (NULL);
}

char	*map_parse_config(t_game *game, t_map *map, char **splited)
{
	int			cnt;
	static int	rows;
	char		*line;
	char		*ret;
	char		*str;

	ret = NULL;
	str = NULL;
	if (splited[0] == NULL)
		return (ft_strjoin("Invalid empty line in map", "\n"));
	line = ft_strjoin_splited((const char **)splited);
	cnt = ft_strlen(line);
	map->size.x = cnt;
	map->size.y = ++rows;
	ret = i_malloc_map_buf(&game->map_config, line, &str);
	ft_strlcat(map->map_buf, line, map->size.x * map->size.y + 1);
	ft_memdel(&str);
	ft_memdel(&line);
	return (ret);
}
