/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:25:30 by eujeong           #+#    #+#             */
/*   Updated: 2022/12/26 17:06:54 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int ny, int nx, t_game *game)
{
	game->p_y = ny;
	game->p_x = nx;
	game->move_cnt++;
	ft_printf("Move count : %d\n", game->move_cnt);
	if (game->map[ny][nx] == 'C')
	{
		game->collectible_cnt++;
		game->map[ny][nx] = '0';
	}
	else if (game->map[ny][nx] == 'E')
	{
		if (clear_check(game))
			finish_game(game);
	}
	draw_map(game);
}
