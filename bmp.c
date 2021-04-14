/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:04:20 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:04:22 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int	write_bmp_header(t_game *game, int size, int fd)
{
	int					i;
	int					tmp;
	unsigned char		bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, size);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = game->img.width;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = game->img.height;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int	get_color(t_game *game, int x, int y)
{
	int					rgb;
	int					color;

	color = *(game->img.data
			+ (x + (game->img.width * (game->img.height - y - 1))));
	rgb = color & 0xFFFFFF;
	return (rgb);
}

static int	write_bmp_data(t_game *game, int pad, int fd)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < game->img.height)
	{
		j = 0;
		while (j < game->img.width)
		{
			color = get_color(game, j, i);
			if (write(fd, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(fd, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	save_bmp(t_game *game)
{
	int					size;
	int					fd;
	int					pad;

	pad = (4 - (game->img.width * 3) % 4) % 4;
	size = 54 + (3 * (game->img.width + pad) * game->img.height);
	fd = open(EXPORT_FILE, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND);
	if (fd < 0)
		return (0);
	if (!write_bmp_header(game, size, fd))
		return (0);
	if (!write_bmp_data(game, pad, fd))
		return (0);
	close(fd);
	return (1);
}
