/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:56:42 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:56:42 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_start_check(t_map *map, char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
			map->map_start = 1;
		i++;
	}
}

static char	*id_check(t_game *game, char **str)
{
	char	*ret;

	ret = NULL;
	if (str[0] != NULL)
	{
		if (ft_strncmp(str[0], P_RESOLUTION, ft_strlen(str[0])) == 0)
			ret = id_parse_resolution(game, str);
		else if (ft_strncmp(str[0], P_TEX_NORTH, ft_strlen(str[0])) == 0)
			ret = id_parse_texture(game, str + 1, 0);
		else if (ft_strncmp(str[0], P_TEX_WEST, ft_strlen(str[0])) == 0)
			ret = id_parse_texture(game, str + 1, 2);
		else if (ft_strncmp(str[0], P_TEX_EAST, ft_strlen(str[0])) == 0)
			ret = id_parse_texture(game, str + 1, 3);
		else if (ft_strncmp(str[0], P_SPRITE, ft_strlen(str[0])) == 0)
			ret = id_parse_texture(game, str + 1, 4);
		else if (ft_strncmp(str[0], P_TEX_SOUTH, ft_strlen(str[0])) == 0)
			ret = id_parse_texture(game, str + 1, 1);
		else if (ft_strncmp(str[0], P_FLOOR_COLOR, ft_strlen(str[0])) == 0)
			ret = id_parse_color(game, str);
		else if (ft_strncmp(str[0], P_CEILING_COLOR, ft_strlen(str[0])) == 0)
			ret = id_parse_color(game, str);
	}
	return (ret);
}

static char	*id_verification_check(t_game *game, char **str)
{
	int		id_checked;

	id_checked = 0;
	if (str[0] != NULL)
	{
		if ((ft_strncmp(str[0], P_RESOLUTION, ft_strlen(str[0])) == 0)
			|| (ft_strncmp(str[0], P_TEX_NORTH, ft_strlen(str[0])) == 0)
			|| (ft_strncmp(str[0], P_TEX_WEST, ft_strlen(str[0])) == 0)
			|| (ft_strncmp(str[0], P_TEX_EAST, ft_strlen(str[0])) == 0)
			|| (ft_strncmp(str[0], P_SPRITE, ft_strlen(str[0]) + 1) == 0)
			|| (ft_strncmp(str[0], P_TEX_SOUTH, ft_strlen(str[0]) + 1) == 0)
			|| (ft_strncmp(str[0], P_FLOOR_COLOR, ft_strlen(str[0])) == 0)
			|| (ft_strncmp(str[0], P_CEILING_COLOR, ft_strlen(str[0])) == 0))
			id_checked = 1;
		if (id_checked == 0 && game->map_config.cnt != 8)
		{
			map_start_check(&game->map_config, str[0]);
			if (game->map_config.map_start != 1)
				return (ft_strjoin("invalid id : ", str[0]));
			else
				return (ft_strjoin("invalid id ", "map" ));
		}
	}
	return (NULL);
}

char	*map_info_parse(t_game *game, char *line, char **str)
{
	char	*ret;

	ret = NULL;
	map_start_check(&game->map_config, line);
	if (game->map_config.map_start == 1)
	{
		ret = map_parse_config(game, &game->map_config, str);
		if (ret)
			return (ret);
	}
	else
		return (NULL);
	return (ret);
}

char	*map_parse_line(t_game *game, char *line)
{
	char	**str;
	char	*ret;

	str = ft_split(line, ' ');
	if (game->map_config.cnt != 8)
	{
		ret = id_verification_check(game, str);
		if (ret == NULL)
			ret = id_check(game, str);
	}
	else
		ret = map_info_parse(game, line, str);
	ft_memdel_2dim(str);
	return (ret);
}
