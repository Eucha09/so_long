/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:26:50 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/04 20:24:52 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_img(int y, int x, void *img, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	draw_player(t_game *game)
{
	int			i;

	i = (game->p.dir * 4) + (game->frame % 8 / 2);
	if (game->p.ny == 0 && game->p.nx == 0)
		i = game->p.dir * 4;
	if (game->state == GAME_OVER)
	{
		i = 16 + (game->frame - game->game_over_time) % 44 / 4;
		if (i == 26)
			finish_game(game);
	}
	draw_img(game->p.y, game->p.x, game->img_player[i], game);
}

void	draw_ghosts(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->ghost_cnt)
	{
		j = (i % 4 * 8) + (game->g[i].dir * 2) + (game->frame % 4 / 2);
		if (game->g[i].ny == 0 && game->g[i].nx == 0)
			j = (i % 4 * 8);
		draw_img(game->g[i].y, game->g[i].x, game->img_ghost[j], game);
		i++;
	}
}

void	draw_tiles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '0')
				draw_img(i * 32, j * 32, game->img_empty, game);
			else if (game->map[i][j] == '1')
				draw_img(i * 32, j * 32, game->img_wall, game);
			else if (game->map[i][j] == 'C')
				draw_img(i * 32, j * 32, game->img_collectible, game);
			else if (game->map[i][j] == 'E')
				draw_img(i * 32, j * 32, game->img_exit, game);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_tiles(game);
	if (game->state != GAME_FINISHED)
		draw_player(game);
	if (game->state == GAME_READY || game->state == GAME_STARTED)
		draw_ghosts(game);
	put_move_cnt(game);
}
