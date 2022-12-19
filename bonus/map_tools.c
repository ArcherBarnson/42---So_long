/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:04:38 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 11:09:03 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_mlx_place_tile(t_mlx_global *game, int x, int y, int size)
{
	if (game->map[x][y] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->ground, y * size, x * size);
	if (game->map[x][y] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall, y * size, x * size);
	if (game->map[x][y] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->player[0], y * size, x * size);
	if (game->map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->exit[0], y * size, x * size);
	if (game->map[x][y] == 'E' && game->c == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->exit[1], y * size, x * size);
	if (game->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->collectible[0],
			y * size, x * size);
	return ;
}

void	replace_tiles(t_mlx_global *game, char old_tile,
		char new_tile, void *new_sprite)
{
	int	**tiles_pos;
	int	tile_count;
	int	i;

	if (old_tile == 'C')
		tile_count = game->c;
	else if (old_tile == 'X')
		tile_count = game->ennemy_count;
	tiles_pos = get_tiles_pos(game, old_tile);
	i = 0;
	while (i < tile_count)
	{
		if (tiles_pos[i][0] != 0 && tiles_pos[i][1] != 0)
		{
			mlx_put_image_to_window(game->mlx, game->window, new_sprite,
				tiles_pos[i][1] * game->sps, tiles_pos[i][0] * game->sps);
			game->map[tiles_pos[i][0]][tiles_pos[i][1]] = new_tile;
		}
		free(tiles_pos[i]);
		i++;
	}
	free(tiles_pos);
	return ;
}

void	animation_handler(t_mlx_global *game)
{
	if (game->sprites->framerate_ctl != RATIO)
		game->sprites->framerate_ctl ++;
	else
	{
		replace_tiles(game, 'X', 'X',
			game->sprites->ennemy[game->sprites->anim_stage]);
		replace_tiles(game, 'C', 'C',
			game->sprites->collectible[game->sprites->anim_stage]);
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->player[game->sprites->anim_stage],
			game->player_pos[1] * game->sps,
			game->player_pos[0] * game->sps);
		if (game->sprites->anim_stage == 2)
			game->sprites->anim_stage = 0;
		else
			game->sprites->anim_stage++;
		game->sprites->framerate_ctl = 0;
	}
	return ;
}

void	draw_map(t_mlx_global *game)
{
	int	x;
	int	y;
	int	size;

	size = game->sps;
	x = 0;
	while (x < game->map_dimensions[1] / size)
	{
		y = 0;
		while (y < game->map_dimensions[0] / size)
		{
			my_mlx_place_tile(game, x, y, size);
			y++;
		}
		x++;
	}
	return ;
}
