/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung-mo <cjung-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:56:07 by cjung-mo          #+#    #+#             */
/*   Updated: 2021/04/12 13:56:07 by cjung-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	engine_loop(t_game *game)
{
	image_clear(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	game_update_window(game);
	if (game->mini_map == 1)
	{
		draw_rectangles(game);
		draw_lines(game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		save_arg;

	save_arg = (argc >= 3 && !ft_strncmp(argv[2],
				"--save", ft_strlen(argv[2]) + 1));
	if (argc < 2 + save_arg)
	{
		printf("Error\nparameter error\n");
		return (1);
	}
	game_engine_init(save_arg, argv[1]);
}
