/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:11:37 by eujeong           #+#    #+#             */
/*   Updated: 2022/12/26 19:35:47 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	error_code;

	game->fd = open(game->file_path, O_RDONLY);
	if (game->fd == -1)
	{
		error(ERROR_FILE_OPEN_FAIL);
		exit_game(game);
	}
	if (!read_map(game->fd, game))
	{
		error(ERROR_MAP_READ_FAIL);
		exit_game(game);
	}
	error_code = is_valid_map(game);
	if (error_code != 0)
	{
		error(error_code);
		exit_game(game);
	}
	game->move_cnt = 0;
	game->collectible_cnt = 0;
	game->finished = 0;
}

void	run_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32,
			"so_long [Pac-Man]");
	mlx_hook(game->win, ON_KEYDOWN, 0, key_action, game);
	mlx_hook(game->win, ON_DESTROY, 0, on_destroy, game);
	load_img(game);
	draw_map(game);
	mlx_loop(game->mlx);
}
