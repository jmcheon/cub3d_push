/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:05:57 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:05:57 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_init(t_img *img)
{
	img->img = NULL;
	img->data = NULL;
	img->size_l = 0;
	img->bpp = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}
