/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_parse_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:55:31 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:55:32 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	i_resolution_max_check(int *w, int *h)
{
	if (*w > MAX_RESOLUTION_WIDTH)
		*w = MAX_RESOLUTION_WIDTH;
	if (*h > MAX_RESOLUTION_HEIGHT)
		*h = MAX_RESOLUTION_HEIGHT;
}

char	*id_parse_resolution(t_game *game, char **str)
{
	int		w;
	int		h;
	int		len;
	char	*ret;

	ret = NULL;
	len = ft_strlen_2dim((const char **)str);
	if (len != 3)
		return (ft_strjoin("Invalid number of resolution factors : ", str[0]));
	ret = decimal_string_validation_check(str);
	if (ret != NULL)
		return (ret);
	if (!(game->img.width == 0 && game->img.height == 0))
		return (ft_strjoin("resolution format already initialized : ", str[0]));
	w = ft_atoi(str[1]);
	h = ft_atoi(str[2]);
	if (w == 0 || h == 0)
		return (ft_strjoin("resolution zero error: ", str[0]));
	i_resolution_max_check(&w, &h);
	game->img.width = w;
	game->img.height = h;
	game->map_config.cnt++;
	return (ret);
}
