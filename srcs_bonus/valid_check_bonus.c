/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:55:10 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/06 15:23:35 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
			return (0);
		i++;
	}
	return (1);
}

int	closed_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (i == 0 && game->map[i][j] != '1')
				return (0);
			if (i == game->height - 1 && game->map[i][j] != '1')
				return (0);
			if (j == 0 && game->map[i][j] != '1')
				return (0);
			if (j == game->width - 1 && game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_exit_coll_start(t_game *game)
{
	int	i;
	int	j;
	int	cnt[256];

	ft_memset(cnt, 0, sizeof(cnt));
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (ft_strchr(MAP_CHARACTERS, game->map[i][j]) == NULL)
				return (0);
			cnt[(unsigned char)(game->map[i][j])]++;
			j++;
		}
		i++;
	}
	game->ghost_cnt = cnt['G'];
	if ((cnt['E'] != 1) || (cnt['C'] == 0) || (cnt['P'] != 1))
		return (0);
	return (1);
}

int	check_path(t_game *game)
{
	int	i;
	int	j;
	int	*visited;

	visited = ft_calloc(sizeof(int), game->width * game->height);
	if (visited == NULL)
		return (0);
	set_player(game);
	dfs(game->p.y / 32, game->p.x / 32, visited, game);
	free(visited);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'E' && visited[game->width * i + j] == 0)
				return (0);
			if (game->map[i][j] == 'C' && visited[game->width * i + j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_map(t_game *game)
{
	if (!is_rectangular(game))
		return (ERROR_MAP_IS_NOT_RECTANGULAR);
	if (!closed_walls(game))
		return (ERROR_MAP_IS_NOT_CLOSED_WALLS);
	if (!check_exit_coll_start(game))
		return (ERROR_MAP_IS_INVALID);
	if (!check_path(game))
		return (ERROR_PATH_IS_INVALID);
	return (0);
}
