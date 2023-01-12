/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:39:02 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/04 20:44:42 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ghost_next_dir(int i, t_game *game)
{
	int	ndir;

	ndir = rand() % 4;
	while (ft_abs(game->g[i].dir - ndir) == 2)
		ndir = rand() % 4;
	game->g[i].ndir = ndir;
}

void	ghost_next_position(int i, t_game *game, int re_cnt)
{
	const int	dy[4] = {0, 1, 0, -1};
	const int	dx[4] = {1, 0, -1, 0};
	int			ny;
	int			nx;

	ny = game->g[i].y / 32 + dy[game->g[i].ndir];
	nx = game->g[i].x / 32 + dx[game->g[i].ndir];
	if (game->map[ny][nx] != '1')
		game->g[i].dir = game->g[i].ndir;
	ny = game->g[i].y / 32 + dy[game->g[i].dir];
	nx = game->g[i].x / 32 + dx[game->g[i].dir];
	if (game->map[ny][nx] == '1')
	{
		ghost_next_dir(i, game);
		if (re_cnt > 3)
			game->g[i].ndir = (game->g[i].dir + 4 - 2) % 4;
		ghost_next_position(i, game, re_cnt + 1);
		return ;
	}
	game->g[i].ny = ny * 32;
	game->g[i].nx = nx * 32;
}

int	get_distance(int n, t_game *game)
{
	int	distance;

	distance = (int)ft_abs(game->p.y - game->g[n].y)
		+ (int)ft_abs(game->p.x - game->g[n].x);
	return (distance);
}

void	move_ghosts(t_game *game)
{
	const int	dy[4] = {0, 1, 0, -1};
	const int	dx[4] = {1, 0, -1, 0};
	int			distance;
	int			i;

	i = 0;
	while (i < game->ghost_cnt)
	{
		if (game->g[i].ny == 0 && game->g[i].nx == 0)
		{
			ghost_next_dir(i, game);
			ghost_next_position(i, game, 0);
		}
		if (game->frame % (32 / game->speed * 5) == 0)
			ghost_next_dir(i, game);
		game->g[i].y = game->g[i].y + dy[game->g[i].dir] * game->speed;
		game->g[i].x = game->g[i].x + dx[game->g[i].dir] * game->speed;
		if (game->g[i].ny == game->g[i].y && game->g[i].nx == game->g[i].x)
			ghost_next_position(i, game, 0);
		distance = get_distance(i, game);
		if (distance <= 16)
			player_die(game);
		i++;
	}
}
