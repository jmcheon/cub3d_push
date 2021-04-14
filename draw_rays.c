/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:54:59 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:55:01 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ray_line_high(t_img *img, t_vec2d *start, t_vec2d *end,
																	int color)
{
	double	dx;
	double	dy;
	double	xi;
	double	p;

	dx = (end->x - start->x);
	dy = (end->y - start->y);
	xi = 1;
	if (dx < 0)
	{
		dx *= -1;
		xi *= -1;
	}
	p = 2 * dx - dy;
	while (start->y <= end->y)
	{
		img->data[(int)start->x + (int)start->y * img->width] = color;
		if (p > 0)
		{
			start->x += xi;
			p -= 2 * dy;
		}
		p += 2 * dx;
		start->y++;
	}
}

static void	draw_ray_line_low(t_img *img, t_vec2d *start, t_vec2d *end,
																	int color)
{
	double	dx;
	double	dy;
	double	yi;
	double	p;

	dx = end->x - start->x;
	dy = end->y - start->y;
	yi = 1;
	if (dy < 0)
	{
		dy *= -1;
		yi *= -1;
	}
	p = 2 * dy - dx;
	while (start->x <= end->x)
	{
		img->data[(int)start->x + (int)start->y * img->width] = color;
		if (p > 0)
		{
			start->y += yi;
			p -= 2 * dx;
		}
		p += 2 * dy;
		start->x++;
	}
}

int	draw_ray_lines(t_img *img, t_vec2d *start, t_vec2d *end, int color)
{
	double	dx;
	double	dy;

	dx = fabs(end->x - start->x);
	dy = fabs(end->y - start->y);
	if (dy < dx)
	{
		if (start->x > end->x)
			draw_ray_line_low(img, end, start, color);
		else
			draw_ray_line_low(img, start, end, color);
	}
	else
	{
		if (start->y > end->y)
			draw_ray_line_high(img, end, start, color);
		else
			draw_ray_line_high(img, start, end, color);
	}
	return (1);
}
