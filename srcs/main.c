/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:37:02 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/06 15:09:39 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_memset(&game, 0, sizeof(game));
	if (argc != 2)
		return (error(ERROR_ARG_IS_INVALID));
	game.file_path = argv[1];
	init_game(&game);
	run_game(&game);
	return (0);
}
