/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:26:50 by eujeong           #+#    #+#             */
/*   Updated: 2022/12/26 17:11:32 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img_empty = mlx_xpm_file_to_image(game->mlx,
			"./textures/Other/Walls/black.xpm", &img_w, &img_h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/Other/Walls/wall.xpm", &img_w, &img_h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./textures/Other/Pacdots/pacdot_food.xpm", &img_w, &img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/Other/Portal/portal.xpm", &img_w, &img_h);
	game->img_player[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/Pac-Man/pac_semi_right.xpm", &img_w, &img_h);
	game->img_player[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/Pac-Man/pac_semi_down.xpm", &img_w, &img_h);
	game->img_player[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/Pac-Man/pac_semi_left.xpm", &img_w, &img_h);
	game->img_player[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/Pac-Man/pac_semi_up.xpm", &img_w, &img_h);
}

void	draw_img(int y, int x, void *img, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			draw_img(i, j, game->img_empty, game);
			if (game->map[i][j] == '1')
				draw_img(i, j, game->img_wall, game);
			else if (game->map[i][j] == 'C')
				draw_img(i, j, game->img_collectible, game);
			else if (game->map[i][j] == 'E')
				draw_img(i, j, game->img_exit, game);
			j++;
		}
		i++;
	}
	if (game->finished == 0)
		draw_img(game->p_y, game->p_x, game->img_player[game->p_dir], game);
}
