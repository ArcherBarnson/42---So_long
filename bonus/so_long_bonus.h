/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:30:07 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 11:10:54 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# define TILES "10PEC"
# define EXTENSION ".ber"
# define LARGE 50
# define L_DIR "./assets/large/"
# define MEDIUM 30
# define M_DIR "./assets/medium/"
# define SMALL 20
# define S_DIR "./assets/small/"
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100
# define RATIO 15
# define DIFFICULTY 7
# define FRAMERATE 20
# define GAME_NAME "So Long"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_sprites
{
	void	**ennemy;
	void	**collectible;
	void	**player;
	void	**exit;
	void	*ground;
	void	*wall;
	int		img_width;
	int		img_height;
	int		framerate_ctl;
	int		anim_stage;
	char	*paths[12];
}			t_sprites;

typedef struct t_mlx_global
{
	void		*mlx;
	void		*window;
	t_sprites	*sprites;
	int			map_dimensions[2];
	int			player_pos[2];
	int			p;
	int			e;
	int			c;
	int			map_fd;
	int			step_count;
	int			sps;
	int			ennemy_count;
	int			**ennemypos;
	char		*map_line;
	char		*spd;
	char		**map;
}				t_mlx_global;

int				**get_tiles_pos(t_mlx_global *game, char tile);
int				err_msg(int err_code, t_mlx_global *game);
int				get_keyboard_event(int keycode, t_mlx_global *game);
int				can_u_move(t_mlx_global *game, int x, int y);
int				move_player(t_mlx_global *game, int x, int y);
int				main_init(char *av1, t_mlx_global *game);
int				where_is_that_char(char c, char *str);
int				verify_extension(char *map_file);
int				check_wall(t_mlx_global *game, int i);
int				check_bounds(t_mlx_global *game);
int				check_tiles(t_mlx_global *game);
int				check_special_tiles(t_mlx_global *game);
int				ft_parsing(char *map_file, t_mlx_global *game);
int				*generate_random_coordinates(int x, int y);
int				count_available_tiles(t_mlx_global *game);
int				load_sprites(t_mlx_global *game);
int				load_ennemies(t_mlx_global *game);
int				check_sprites_integrity(t_mlx_global *game);
int				choose_res(t_mlx_global *game, int x, int y);
void			init_sprite_groups(t_sprites *sprites);
void			reset_all(t_mlx_global *game);
void			set_assets_paths(t_mlx_global *game);
void			unset_assets_paths(t_mlx_global *game);
void			set_map_dimensions(t_mlx_global *game);
void			get_player_pos(t_mlx_global *game);
void			find_tiles(t_mlx_global *game, int **tiles_pos, char tile);
void			my_mlx_place_tile(t_mlx_global *game, int x, int y, int size);
void			draw_map(t_mlx_global *game);
void			replace_tiles(t_mlx_global *game, char old_tile,
					char new_tile, void *new_sprite);
void			animation_handler(t_mlx_global *game);
void			free_tab(void **tab, int len);
void			free_sprite_lists(t_mlx_global *game);
void			free_sprites(t_mlx_global *game);
void			free_game(t_mlx_global *game);
void			exit_game(t_mlx_global *game);
void			place_ennemies(t_mlx_global *game);
void			ft_respawn(t_mlx_global *game);
void			display_step_count(t_mlx_global *game);
void			replace_last_line(t_mlx_global *game);
void			mlx_error(t_mlx_global *game);
void			sprite_error(t_mlx_global *game);
char			*cat_line(char *s1, char *s2);
char			*get_sprite_dir(t_mlx_global *game, int x, int y);
t_mlx_global	*struct_init(void);
t_sprites		*sprites_init(void);
t_data			*load_asset(t_mlx_global *game, void *asset, int i);

#endif
