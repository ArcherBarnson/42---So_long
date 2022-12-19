/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:04:56 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 11:09:29 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_map_dimensions(t_mlx_global *game)
{
	game->map_dimensions[0] = get_line_size(game->map[0]);
	game->map_dimensions[1] = 0;
	while (game->map[game->map_dimensions[1]] != NULL)
		game->map_dimensions[1]++;
	return ;
}

void	get_player_pos(t_mlx_global *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[x] != NULL)
	{
		while (game->map[x][y] != '\n' && game->map[x][y] != '\0')
		{
			if (game->map[x][y] == 'P')
			{
				game->player_pos[0] = x;
				game->player_pos[1] = y;
				return ;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return ;
}

void	find_tiles(t_mlx_global *game, int **tiles_pos, char tile)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	k = 0;
	while (++i < game->map_dimensions[1] / game->sps)
	{
		while (++j < game->map_dimensions[0] / game->sps)
		{
			if (game->map[i][j] == tile)
			{
				tiles_pos[k][0] = i;
				tiles_pos[k][1] = j;
				k++;
			}
		}
		j = -1;
	}
	return ;
}

int	**get_tiles_pos(t_mlx_global *game, char tile)
{
	int	**tiles_pos;
	int	i;
	int	tile_count;

	i = 0;
	if (tile == 'C')
		tile_count = game->c;
	else if (tile == 'X')
		tile_count = game->ennemy_count;
	tiles_pos = (int **)malloc(sizeof(int *) * tile_count);
	if (!tiles_pos)
		return (NULL);
	while (i < tile_count)
	{
		tiles_pos[i] = malloc(sizeof(int) * 2);
		if (!tiles_pos[i])
			exit_game(game);
		tiles_pos[i][0] = 0;
		tiles_pos[i][1] = 0;
		i++;
	}
	find_tiles(game, tiles_pos, tile);
	return (tiles_pos);
}
