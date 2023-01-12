/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:46:49 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/06 15:19:56 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include "error.h"

# define MAP_CHARACTERS	"01CEP"

# define ON_KEYDOWN		2
# define ON_DESTROY		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_R			15

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*file_path;
	int		fd;
	int		width;
	int		height;
	char	**map;
	int		p_y;
	int		p_x;
	int		p_dir;
	int		move_cnt;
	int		collectible_cnt;
	int		finished;
	void	*img_empty;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player[4];
}	t_game;

void	init_game(t_game *game);
void	run_game(t_game *game);

void	finish_game(t_game *game);
void	exit_game(t_game *game);
int		clear_check(t_game *game);
void	re_game(t_game *game);

void	load_img(t_game *game);
void	draw_img(int y, int x, void *img, t_game *game);
void	draw_map(t_game *game);

int		read_map(int fd, t_game *game);
void	clear_map(t_game *game);
void	set_width_height(t_game *game);
void	set_player(t_game *game);

int		is_valid_map(t_game *game);
int		is_rectangular(t_game *game);
int		closed_walls(t_game *game);
int		check_exit_coll_start(t_game *game);
int		check_path(t_game *game);
void	dfs(int y, int x, int *visited, t_game *game);

int		key_action(int key_code, t_game *game);
void	on_key_esc(t_game *game);
void	on_key_r(t_game *game);
void	on_key_wasd(int key_code, t_game *game);
int		on_destroy(t_game *game);

void	move_player(int ny, int nx, t_game *game);

#endif
