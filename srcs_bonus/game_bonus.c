/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:06:22 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/04 20:24:43 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_game(t_game *game)
{
	clear_map(game);
	exit(0);
}

void	finish_game(t_game *game)
{
	if (game->state == GAME_OVER)
		ft_printf("Game Over...\n");
	else
		ft_printf("Clear! your move count %d\n", game->move_cnt);
	game->state = GAME_FINISHED;
}

void	re_game(t_game *game)
{
	clear_map(game);
	init_game(game);
	draw_map(game);
	ft_printf("Restart!\n");
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
