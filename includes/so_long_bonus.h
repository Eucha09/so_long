/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:46:49 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/06 15:22:32 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include "assets_bonus.h"
# include "error.h"

# define MAP_CHARACTERS	"01CEPG"

# define ON_KEYDOWN		2
# define ON_DESTROY		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_R			15
# define KEY_UP			126
# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124

# define GAME_READY		0
# define GAME_STARTED	1
# define GAME_OVER		2
# define GAME_FINISHED	3

typedef struct s_pos
{
	int	y;
	int	x;
	int	ny;
	int	nx;
	int	dir;
	int	ndir;
}	t_pos;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*file_path;
	int		fd;
	char	**map;
	int		width;
	int		height;
	int		state;
	int		frame;
	int		speed;
	int		game_over_time;
	t_pos	p;
	int		move_cnt;
	int		collectible_cnt;
	t_pos	*g;
	int		ghost_cnt;
	void	*img_empty;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player[27];
	void	*img_ghost[32];
}	t_game;

void	init_game(t_game *game);
void	run_game(t_game *game);

int		update(t_game *game);

void	exit_game(t_game *game);
void	finish_game(t_game *game);
void	re_game(t_game *game);
int		clear_check(t_game *game);

int		read_map(int fd, t_game *game);
void	clear_map(t_game *game);
void	set_width_height(t_game *game);
void	set_player(t_game *game);
int		set_ghost(t_game *game);

int		is_valid_map(t_game *game);
void	dfs(int y, int x, int *visited, t_game *game);

void	*load_xpm_file(char *path, t_game *game);
void	load_player_img(t_game *game);
void	load_ghosts_img(t_game *game);
void	load_img(t_game *game);

void	draw_map(t_game *game);

int		key_action(int key_code, t_game *game);
int		on_destroy(t_game *game);

void	player_next_position(t_game *game);
void	move_player(t_game *game);
void	player_die(t_game *game);
void	put_move_cnt(t_game *game);

void	move_ghosts(t_game *game);

#endif
