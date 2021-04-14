/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:05:27 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/14 14:05:27 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_engine_init(int save_arg, char *path)
{
	t_game	game;

	player_init(&game);
	game.ray.zbuffer = NULL;
	game.mini_map = 0;
	game.map = NULL;
	image_init(&game.img);
	game.mlx = mlx_init();
	map_load(&game, path);
	image_data_load(&game);
	if (save_arg == 1)
	{
		game_update_window(&game);
		export_bmp(&game);
	}
	game.win = mlx_new_window(game.mlx, game.img.width,
			game.img.height, WINDOW_NAME);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, (1L <<0), &key_press, &game);
	mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, (1L <<17), &mouse_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, (1L <<0), &game_close, &game);
	mlx_loop_hook(game.mlx, &engine_loop, &game);
	mlx_loop(game.mlx);
}
