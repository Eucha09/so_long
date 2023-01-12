/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:03:39 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/04 20:24:46 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*load_xpm_file(char *path, t_game *game)
{
	int	img_w;
	int	img_h;

	return (mlx_xpm_file_to_image(game->mlx, path, &img_w, &img_h));
}

void	load_tiles_img(t_game *game)
{
	game->img_empty = load_xpm_file(IMG_EMPTY, game);
	game->img_wall = load_xpm_file(IMG_WALL, game);
	game->img_collectible = load_xpm_file(IMG_COLLECTIBLE, game);
	game->img_exit = load_xpm_file(IMG_EXIT, game);
}

void	load_img(t_game *game)
{
	load_tiles_img(game);
	load_player_img(game);
	load_ghosts_img(game);
}
