/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:55:43 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:55:44 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_clear(t_game *game)
{
	ft_bzero(game->img.data, game->img.bpp / 8
		* game->img.width * game->img.height);
}
