/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:58:33 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 09:58:35 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
