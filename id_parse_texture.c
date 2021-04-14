/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_parse_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:55:38 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:55:38 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*load_texture(t_game *game, char *path, int flag)
{
	t_img	img;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_strjoin("wrong path :", path));
	if (game->map_config.id[flag] == 1)
		return (ft_strjoin("already assgined image error with path :", path));
	load_image(game, game->map_config.texture[flag], path, &img);
	return (NULL);
}

static char	*malloc_texture(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	if (*game->map_config.texture == NULL)
	{
		while (i < 6)
		{
			game->map_config.texture[i] = (int *)malloc(sizeof(int)
					* (TEX_HEIGHT * TEX_WIDTH));
			if (!game->map_config.texture[i++])
				return (ft_strjoin("error malloc texture height",
						ft_itoa(TEX_HEIGHT * TEX_WIDTH)));
		}
		i = 0;
		while (i < 6)
		{
			j = 0;
			while (j < TEX_WIDTH * TEX_HEIGHT)
				game->map_config.texture[i][j++] = 0;
			i++;
		}
	}
	return (NULL);
}

char	*id_parse_texture(t_game *game, char **path, int flag)
{
	char	*ret;
	char	*line;

	line = ft_strjoin_splited((const char **) path);
	ret = malloc_texture(game);
	ret = load_texture(game, line, flag);
	game->map_config.cnt++;
	game->map_config.id[flag] = 1;
	free(line);
	return (ret);
}
