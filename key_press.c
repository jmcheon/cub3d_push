/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:55:50 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:06:19 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	key_left_right_pressed(int key, t_game *game, t_player *player)
{
	if (key == K_D)
	{
		if (!game->map[(int)(player->pos.y)][(int)(player->pos.x
					+ player->plane.x * player->move_sp)])
			player->pos.x += player->plane.x * player->move_sp;
		if (!game->map[(int)(player->pos.y + player->plane.y
				* player->move_sp)][(int)(player->pos.x)])
			player->pos.y += player->plane.y * player->move_sp;
	}
	if (key == K_A)
	{
		if (!game->map[(int)(player->pos.y)][(int)(player->pos.x
					- player->plane.x * player->move_sp)])
			player->pos.x -= player->plane.x * player->move_sp;
		if (!game->map[(int)(player->pos.y - player->plane.y
				* player->move_sp)][(int)(player->pos.x)])
			player->pos.y -= player->plane.y * player->move_sp;
	}
}

static void	key_for_backward_pressed(int key, t_game *game, t_player *player)
{
	if (key == K_W)
	{
		if (!game->map[(int)(player->pos.y)][(int)(player->pos.x
					+ player->dir.x * player->move_sp)])
			player->pos.x += player->dir.x * player->move_sp;
		if (!game->map[(int)(player->pos.y + player->dir.y
				* player->move_sp)][(int)(player->pos.x)])
			player->pos.y += player->dir.y * player->move_sp;
	}
	if (key == K_S)
	{
		if (!game->map[(int)(player->pos.y)][(int)(player->pos.x
					- player->dir.x * player->move_sp)])
			player->pos.x -= player->dir.x * player->move_sp;
		if (!game->map[(int)(player->pos.y - player->dir.y
				* player->move_sp)][(int)(player->pos.x)])
			player->pos.y -= player->dir.y * player->move_sp;
	}
}

static void	key_rotate_right_pressed(int key, t_player *player)
{
	double	oldDirectionX;
	double	oldPlaneX;

	oldDirectionX = player->dir.x;
	oldPlaneX = player->plane.x;
	if (key == K_AR_R)
	{
		player->dir.x = player->dir.x * cos(-player->rot_sp)
			- player->dir.y * sin(-player->rot_sp);
		player->dir.y = oldDirectionX * sin(-player->rot_sp)
			+ player->dir.y * cos(-player->rot_sp);
		player->plane.x = player->plane.x * cos(-player->rot_sp)
			- player->plane.y * sin(-player->rot_sp);
		player->plane.y = oldPlaneX * sin(-player->rot_sp)
			+ player->plane.y * cos(-player->rot_sp);
	}
}

static void	key_rotate_left_pressed(int key, t_player *player)
{
	double	oldDirectionX;
	double	oldPlaneX;

	oldDirectionX = player->dir.x;
	oldPlaneX = player->plane.x;
	if (key == K_AR_L)
	{
		player->dir.x = player->dir.x * cos(player->rot_sp)
			- player->dir.y * sin(player->rot_sp);
		player->dir.y = oldDirectionX * sin(player->rot_sp)
			+ player->dir.y * cos(player->rot_sp);
		player->plane.x = player->plane.x * cos(player->rot_sp)
			- player->plane.y * sin(player->rot_sp);
		player->plane.y = oldPlaneX * sin(player->rot_sp)
			+ player->plane.y * cos(player->rot_sp);
	}
}

int	key_press(int key, t_game *game)
{
	if (key == K_D || key == K_A)
		key_left_right_pressed(key, game, &game->player);
	if (key == K_W || key == K_S)
		key_for_backward_pressed(key, game, &game->player);
	if (key == K_E)
	{
		if (game->mini_map == 1)
			game->mini_map = 0;
		else
			game->mini_map = 1;
	}
	if (key == K_AR_L)
		key_rotate_left_pressed(key, &game->player);
	if (key == K_AR_R)
		key_rotate_right_pressed(key, &game->player);
	if (key == K_ESC)
		exit(0);
	return (0);
}
