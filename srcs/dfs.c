/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:27:47 by eujeong           #+#    #+#             */
/*   Updated: 2022/12/23 18:43:29 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(int y, int x, int *visited, t_game *game)
{
	const int	dy[4] = {-1, 1, 0, 0};
	const int	dx[4] = {0, 0, -1, 1};
	int			i;
	int			ny;
	int			nx;

	visited[game->width * y + x] = 1;
	i = 0;
	while (i < 4)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (visited[game->width * ny + nx] == 0 && game->map[ny][nx] != '1')
			dfs(ny, nx, visited, game);
		i++;
	}
}
