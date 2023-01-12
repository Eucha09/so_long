/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:52:39 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/04 20:26:45 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_player_die_img(int *i, t_game *game)
{
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_1, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_2, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_3, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_4, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_5, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_6, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_7, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_8, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_9, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_10, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DIE_11, game);
}

void	load_player_move_img(int *i, t_game *game)
{
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_RIGHT_1, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_RIGHT_2, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_RIGHT_3, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_RIGHT_4, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DOWN_1, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DOWN_2, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DOWN_3, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_DOWN_4, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_LEFT_1, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_LEFT_2, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_LEFT_3, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_LEFT_4, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_UP_1, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_UP_2, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_UP_3, game);
	game->img_player[(*i)++] = load_xpm_file(IMG_PLAYER_UP_4, game);
}

void	load_player_img(t_game *game)
{
	int	i;

	i = 0;
	load_player_move_img(&i, game);
	load_player_die_img(&i, game);
}
