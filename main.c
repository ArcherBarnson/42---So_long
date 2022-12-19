/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:59:41 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 11:00:19 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/so_long.h"

int	main_init(char *av1, t_mlx_global *game)
{
	int	err_code;

	if (!game)
		return (-1);
	err_code = ft_parsing(av1, game);
	if (err_code != 0)
		return (err_code);
	set_map_dimensions(game);
	get_player_pos(game);
	game->sps = choose_res(game, 1050, 1680);
	game->spd = get_sprite_dir(game, 1050, 1680);
	if (game->sps == 0 || game->spd == NULL)
	{
		write(2, "Map too big !\n", 14);
		return (-3);
	}
	game->sprites->img_height = game->sps;
	game->sprites->img_width = game->sps;
	game->map_dimensions[0] *= game->sps;
	game->map_dimensions[1] *= game->sps;
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_global	*game;
	int				err_code;

	err_code = 0;
	if (ac != 2)
		return (err_msg(0, NULL));
	game = struct_init();
	err_code = main_init(av[1], game);
	if (err_code != 0)
		return (err_msg(err_code, game));
	game->mlx = mlx_init();
	if (!game->mlx)
		mlx_error(game);
	if (load_sprites(game) == -1)
		sprite_error(game);
	game->window = mlx_new_window(game->mlx, game->map_dimensions[0],
			game->map_dimensions[1], GAME_NAME);
	draw_map(game);
	mlx_hook(game->window, 2, 1L << 0, get_keyboard_event, game);
	mlx_hook(game->window, 33, 1L << 17, (void *)exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
