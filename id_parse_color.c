/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:55:25 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:55:26 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_convert_to_rgb(int r, int g, int b)
{
	int		rgb;

	rgb = (r * 256 * 256) + (g * 256) + b;
	return (rgb);
}

static char	*i_parse_color(t_game *game, char **str, char **split)
{
	int		color;
	int		rgb[3];

	rgb[0] = ft_atoi(split[0]);
	rgb[1] = ft_atoi(split[1]);
	rgb[2] = ft_atoi(split[2]);
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		return (ft_strjoin("invalid color value ", *str));
	color = ft_convert_to_rgb(rgb[0], rgb[1], rgb[2]);
	if (ft_strncmp(str[0], P_FLOOR_COLOR, ft_strlen(str[0])) == 0)
	{
		if (game->map_config.floor_color == -1)
			game->map_config.floor_color = color;
		else
			return (ft_strjoin("already assgined floor color : ", str[0]));
	}
	if (ft_strncmp(str[0], P_CEILING_COLOR, ft_strlen(str[0])) == 0)
	{
		if (game->map_config.ceiling_color == -1)
			game->map_config.ceiling_color = color;
		else
			return (ft_strjoin("already assgined ceiling color : ", str[0]));
	}
	return (NULL);
}

char	*id_parse_color(t_game *game, char **str)
{
	int		len;
	char	**split;
	char	*ret;

	ret = NULL;
	len = ft_strlen_2dim((const char **)str);
	if (len == 2)
	{
		split = ft_split(str[1], ',');
		len = ft_strlen_2dim((const char **)split);
		if (len == 3)
		{
			ret = decimal_string_validation_check(split);
			if (ret != NULL)
				return (ret);
		}
		else
			return (ft_strjoin("invalid format ", str[0]));
	}
	else
		return (ft_strjoin("invalid format ", str[0]));
	ret = i_parse_color(game, str, split);
	game->map_config.cnt++;
	ft_memdel_2dim(split);
	return (ret);
}
