/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:59:20 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 11:06:34 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_u_move(t_mlx_global *game, int x, int y)
{
	if (game->map[game->player_pos[0] + x][game->player_pos[1] + y] == '0')
	{
		print_step_count(game);
		return (0);
	}
	if (game->map[game->player_pos[0] + x][game->player_pos[1] + y] == 'C')
	{
		game->c--;
		if (game->c == 0)
			draw_map(game);
		print_step_count(game);
		return (0);
	}
	if (game->map[game->player_pos[0] + x][game->player_pos[1] + y] == 'E'
		&& game->c == 0)
	{
		print_step_count(game);
		return (1);
	}
	else
		return (-1);
}
