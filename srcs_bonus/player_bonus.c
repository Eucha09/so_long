/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:25:30 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/04 20:28:14 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_next_position(t_game *game)
{
	const int	dy[4] = {0, 1, 0, -1};
	const int	dx[4] = {1, 0, -1, 0};
	int			ny;
	int			nx;

	ny = game->p.y / 32 + dy[game->p.ndir];
	nx = game->p.x / 32 + dx[game->p.ndir];
	if (game->map[ny][nx] != '1')
		game->p.dir = game->p.ndir;
	ny = game->p.y / 32 + dy[game->p.dir];
	nx = game->p.x / 32 + dx[game->p.dir];
	if (game->map[ny][nx] == '1')
	{
		ny = 0;
		nx = 0;
	}
	game->p.ny = ny * 32;
	game->p.nx = nx * 32;
}

void	move_player(t_game *game)
{
	const int	dy[4] = {0, 1, 0, -1};
	const int	dx[4] = {1, 0, -1, 0};

	if (game->p.ny == 0 && game->p.nx == 0)
		return ;
	game->p.y = game->p.y + dy[game->p.dir] * game->speed;
	game->p.x = game->p.x + dx[game->p.dir] * game->speed;
	if (game->p.ny == game->p.y && game->p.nx == game->p.x)
	{
		game->move_cnt++;
		ft_printf("Move count : %d\n", game->move_cnt);
		if (game->map[game->p.y / 32][game->p.x / 32] == 'C')
		{
			game->collectible_cnt++;
			game->map[game->p.y / 32][game->p.x / 32] = '0';
		}
		else if (game->map[game->p.y / 32][game->p.x / 32] == 'E')
		{
			if (clear_check(game))
				finish_game(game);
		}
		player_next_position(game);
	}
}

void	player_die(t_game *game)
{
	game->state = GAME_OVER;
	game->game_over_time = game->frame;
}

void	put_move_cnt(t_game *game)
{
	char	*str;
	char	*count;

	count = ft_itoa(game->move_cnt);
	str = ft_strjoin("Movement Count : ", count);
	mlx_string_put(game->mlx, game->win,
		6, game->height * 32 + 20, 0xccccff, str);
	free(count);
	free(str);
}
