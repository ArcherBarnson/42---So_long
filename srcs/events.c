/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:58:10 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 09:58:11 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(t_mlx_global *game, int x, int y)
{
	int	movement_handling;

	movement_handling = can_u_move(game, x, y);
	if (movement_handling == -1)
		return (0);
	if (movement_handling == 1)
	{
		game->step_count++;
		exit_game(game);
	}
	else
	{
		game->map[game->player_pos[0]][game->player_pos[1]] = '0';
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->ground, game->player_pos[1] * game->sps,
			game->player_pos[0] * game->sps);
		game->player_pos[0] += x;
		game->player_pos[1] += y;
		game->map[game->player_pos[0]][game->player_pos[1]] = 'P';
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->player[0], game->player_pos[1] * game->sps,
			game->player_pos[0] * game->sps);
		game->step_count++;
	}
	return (0);
}

int	get_keyboard_event(int keycode, t_mlx_global *game)
{
	if (keycode == ESC)
	{
		exit_game(game);
		return (-1);
	}
	else if (keycode == UP || keycode == W)
		move_player(game, -1, 0);
	else if (keycode == DOWN || keycode == S)
		move_player(game, 1, 0);
	else if (keycode == RIGHT || keycode == D)
		move_player(game, 0, 1);
	else if (keycode == LEFT || keycode == A)
		move_player(game, 0, -1);
	return (0);
}
