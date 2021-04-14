/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:04:56 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:04:57 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	export_bmp(t_game *game)
{
	if (!save_bmp(game))
		error_exit(ft_strjoin("filed to save bmp ", "file"));
	return (game_close(game));
}
