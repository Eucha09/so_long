CFLAGS = -Wall -Wextra -Werror
NAME = so_long
INCLUDES = includes
SOURCES =	srcs/main.c\
			srcs/so_long.c\
			srcs/game.c\
			srcs/map.c\
			srcs/valid_check.c\
			srcs/render.c\
			srcs/input_key.c\
			srcs/player.c\
			srcs/error.c\
			srcs/dfs.c
SOURCES_BONUS =	srcs_bonus/main_bonus.c\
				srcs_bonus/so_long_bonus.c\
				srcs_bonus/game_bonus.c\
				srcs_bonus/map_bonus.c\
				srcs_bonus/valid_check_bonus.c\
				srcs_bonus/load_bonus.c\
				srcs_bonus/load_player_bonus.c\
				srcs_bonus/load_ghosts_bonus.c\
				srcs_bonus/render_bonus.c\
				srcs_bonus/input_key_bonus.c\
				srcs_bonus/player_bonus.c\
				srcs_bonus/ghost_bonus.c\
				srcs_bonus/error_bonus.c\
				srcs_bonus/dfs_bonus.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
BONUS_CHECK = bonus_check

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C mlx
	make -C Libft
	cc $^ -LLibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ -I $(INCLUDES)

bonus : $(BONUS_CHECK)

$(BONUS_CHECK) : $(OBJECTS_BONUS)
	make -C mlx
	make -C Libft
	cc $^ -LLibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I $(INCLUDES)
	touch $@

%.o : %.c
	cc $(CFLAGS) -ILibft/includes -Imlx -c $^ -o $@ -I $(INCLUDES)

clean :
	make clean -C Libft
	make clean -C mlx
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	make fclean -C Libft
	rm -f $(NAME) $(BONUS_CHECK)

re : fclean all

.PHONY : all bonus clean fclean re