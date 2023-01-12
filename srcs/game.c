/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:06:22 by eujeong           #+#    #+#             */
/*   Updated: 2022/12/26 17:29:51 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	re_game(t_game *game)
{
	clear_map(game);
	init_game(game);
	draw_map(game);
	ft_printf("Restart!\n");
}

void	finish_game(t_game *game)
{
	ft_printf("Clear! your move count %d\n", game->move_cnt);
	game->finished = 1;
}

void	exit_game(t_game *game)
{
	clear_map(game);
	exit(0);
}

int	clear_check(t_game *game)
{
	int	i;
	int	j;
	int	clear;

	clear = 1;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				clear = 0;
			j++;
		}
		i++;
	}
	return (clear);
}
