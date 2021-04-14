/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:56:30 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:56:30 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*map_load_extention_check(char *path)
{
	char	*extention;
	int		fd;

	extention = ft_strrchr(path, '.');
	if (extention == NULL)
		return (ft_strjoin("extention is ", "null"));
	if (ft_strncmp(extention, P_EXTENTION, ft_strlen(extention) + 1) != 0)
		return (ft_strjoin("invalid extention : ", extention));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_strjoin("file doesn't exist : ", path));
	return (NULL);
}

static void	malloc_ray_zbuffer(t_game *game, t_ray *ray)
{
	if (ray->zbuffer == NULL)
	{
		ray->zbuffer = (double *)malloc(sizeof(double) * (game->img.width + 1));
		if (!game->ray.zbuffer)
			error_exit(ft_strjoin("zbuffer size ", "error"));
	}
}

void	map_load(t_game *game, char *path)
{
	int		fd;
	char	*line;
	char	*error;

	fd = open(path, O_RDONLY);
	error = map_load_extention_check(path);
	if (error != NULL)
		error_exit(error);
	map_init(&game->map_config);
	while (get_next_line(fd, &line))
	{
		error = map_parse_line(game, line);
		if (error != NULL)
			error_exit(error);
		ft_memdel(&line);
	}
	if (line != NULL)
		ft_memdel(&line);
	error = map_create(game, &game->map_config);
	if (error != NULL)
		error_exit(error);
	malloc_ray_zbuffer(game, &game->ray);
}
