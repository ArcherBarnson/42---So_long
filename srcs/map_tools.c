/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:58:20 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 11:04:38 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	draw_map(t_mlx_global *game)
{
	int	x;
	int	y;
	int	size;

	x = 0;
	size = game->sps;
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
