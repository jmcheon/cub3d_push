/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_data_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:05:49 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:05:50 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_data_load(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx,
			game->img.width, game->img.height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
}
