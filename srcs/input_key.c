/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:21:07 by eujeong           #+#    #+#             */
/*   Updated: 2022/12/26 19:45:37 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_action(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		on_key_esc(game);
	else if (key_code == KEY_R)
		on_key_r(game);
	else if (key_code == KEY_W || key_code == KEY_A
		|| key_code == KEY_S || key_code == KEY_D)
		on_key_wasd(key_code, game);
	return (0);
}

void	on_key_esc(t_game *game)
{
	exit_game(game);
}

void	on_key_r(t_game *game)
{
	re_game(game);
}

void	on_key_wasd(int key_code, t_game *game)
{
	const int	dy[4] = {0, 1, 0, -1};
	const int	dx[4] = {1, 0, -1, 0};
	int			ny;
	int			nx;

	if (game->finished == 1)
		return ;
	if (key_code == KEY_W)
		game->p_dir = 3;
	else if (key_code == KEY_A)
		game->p_dir = 2;
	else if (key_code == KEY_S)
		game->p_dir = 1;
	else if (key_code == KEY_D)
		game->p_dir = 0;
	ny = game->p_y + dy[game->p_dir];
	nx = game->p_x + dx[game->p_dir];
	if (game->map[ny][nx] == '1')
		return ;
	move_player(ny, nx, game);
}

int	on_destroy(t_game *game)
{
	exit_game(game);
	return (0);
}
