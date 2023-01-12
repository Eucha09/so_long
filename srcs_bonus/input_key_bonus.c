/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:21:07 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/04 20:26:23 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	on_key_esc(t_game *game)
{
	exit_game(game);
}

void	on_key_r(t_game *game)
{
	re_game(game);
}

int	on_destroy(t_game *game)
{
	exit_game(game);
	return (0);
}

void	on_key_wasd(int key_code, t_game *game)
{
	int	dir;

	dir = 0;
	if (game->state == GAME_READY)
		game->state = GAME_STARTED;
	if (key_code == KEY_W || key_code == KEY_UP)
		dir = 3;
	else if (key_code == KEY_A || key_code == KEY_LEFT)
		dir = 2;
	else if (key_code == KEY_S || key_code == KEY_DOWN)
		dir = 1;
	else if (key_code == KEY_D || key_code == KEY_RIGHT)
		dir = 0;
	game->p.ndir = dir;
	if (game->p.ny == 0 && game->p.nx == 0)
		player_next_position(game);
}

int	key_action(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		on_key_esc(game);
	else if (key_code == KEY_R)
		on_key_r(game);
	else if (key_code == KEY_W || key_code == KEY_A
		|| key_code == KEY_S || key_code == KEY_D
		|| key_code == KEY_UP || key_code == KEY_LEFT
		|| key_code == KEY_DOWN || key_code == KEY_RIGHT)
		on_key_wasd(key_code, game);
	return (0);
}
