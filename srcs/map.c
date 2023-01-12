/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:28:04 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/06 14:51:42 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->p_y = i;
				game->p_x = j;
				game->p_dir = 0;
				game->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
