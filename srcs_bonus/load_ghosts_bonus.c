/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ghosts_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:52:27 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/04 20:26:35 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_ghost_red_img(int *i, t_game *game)
{
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_R_RIGHT_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_R_RIGHT_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_R_DOWN_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_R_DOWN_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_R_LEFT_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_R_LEFT_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_R_UP_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_R_UP_2, game);
}

void	load_ghost_blue_img(int *i, t_game *game)
{
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_B_RIGHT_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_B_RIGHT_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_B_DOWN_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_B_DOWN_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_B_LEFT_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_B_LEFT_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_B_UP_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_B_UP_2, game);
}

void	load_ghost_pink_img(int *i, t_game *game)
{
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_K_RIGHT_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_K_RIGHT_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_K_DOWN_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_K_DOWN_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_K_LEFT_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_K_LEFT_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_K_UP_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_K_UP_2, game);
}

void	load_ghost_orange_img(int *i, t_game *game)
{
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_O_RIGHT_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_O_RIGHT_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_O_DOWN_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_O_DOWN_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_O_LEFT_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_O_LEFT_2, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_O_UP_1, game);
	game->img_ghost[(*i)++] = load_xpm_file(IMG_GHOST_O_UP_2, game);
}

void	load_ghosts_img(t_game *game)
{
	int	i;

	i = 0;
	load_ghost_red_img(&i, game);
	load_ghost_blue_img(&i, game);
	load_ghost_pink_img(&i, game);
	load_ghost_orange_img(&i, game);
}
