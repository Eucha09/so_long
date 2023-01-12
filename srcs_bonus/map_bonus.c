/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:28:04 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/06 15:07:45 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	read_map(int fd, t_game *game)
{
	char	*map;
	char	*line;
	char	*temp;

	map = ft_strdup("");
	if (map == NULL)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = map;
		map = ft_strjoin(map, line);
		free(temp);
		free(line);
		if (map == NULL)
			return (0);
		line = get_next_line(fd);
	}
	game->map = ft_split(map, '\n');
	free(map);
	if (game->map == NULL)
		return (0);
	set_width_height(game);
	return (1);
}

void	clear_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map != NULL && game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game->g);
	if (game->fd != -1)
		close(game->fd);
}

void	set_width_height(t_game *game)
{
	int	i;

	game->width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
		i++;
	game->height = i;
}

void	set_player(t_game *game)
{
	int	i;
	int	j;

	ft_memset(&(game->p), 0, sizeof(game->p));
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->p.y = i * 32;
				game->p.x = j * 32;
				game->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

int	set_ghost(t_game *game)
{
	int	i;
	int	j;
	int	cnt;

	game->g = ft_calloc(sizeof(t_pos), game->ghost_cnt);
	if (game->g == NULL)
		return (error(ERROR_GHOST_MALLOC_FAIL));
	cnt = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'G')
			{
				game->g[cnt].y = i * 32;
				game->g[cnt++].x = j * 32;
				game->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (0);
}
