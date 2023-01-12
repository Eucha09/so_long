/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:11:37 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/06 14:54:16 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_seting(t_game *game)
{
	if (set_ghost(game))
		exit_game(game);
	game->state = GAME_READY;
	game->frame = 0;
	game->speed = 4;
	game->move_cnt = 0;
	game->collectible_cnt = 0;
}

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
	init_seting(game);
}

void	run_game(t_game *game)
{
	int	win_width;
	int	win_height;

	win_width = ft_max(game->width, 7) * 32;
	win_height = (game->height + 1) * 32;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			win_width, win_height, "so_long [Pac-Man]");
	mlx_hook(game->win, ON_KEYDOWN, 0, key_action, game);
	mlx_hook(game->win, ON_DESTROY, 0, on_destroy, game);
	load_img(game);
	draw_map(game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
}

int	update(t_game *game)
{
	if (game->state == GAME_STARTED)
	{
		move_player(game);
		move_ghosts(game);
	}
	draw_map(game);
	game->frame++;
	return (0);
}
