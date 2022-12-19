/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:05:50 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 11:09:59 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	cross_animation(t_mlx_global *game, int *rl, int *du)
{
	while (rl[0] * game->sps < game->map_dimensions[1] - game->sps
		|| rl[1] * game->sps >= game->sps || du[1] * game->sps >= game->sps
		|| du[0] * game->sps < game->map_dimensions[1] - game->sps)
	{
		if ((rl[0]++) * (game->sps) < game->map_dimensions[0] - game->sps)
			game->map[rl[2]][rl[0]] = 'C';
		if ((rl[1]--) * (game->sps) >= game->sps)
			game->map[rl[2]][rl[1]] = 'C';
		if ((du[0]++) * (game->sps) < game->map_dimensions[1] - game->sps)
			game->map[du[0]][du[2]] = 'C';
		if ((du[1]--) * (game->sps) >= game->sps)
			game->map[du[1]][du[2]] = 'C';
		draw_map(game);
	}
	return ;
}

void	wall_down(t_mlx_global *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_dimensions[1] / game->sps)
	{
		while (j < game->map_dimensions[0] / game->sps - 1)
		{
			game->map[i][j] = '1';
			j++;
		}
		j = 0;
		i++;
		draw_map(game);
	}
	return ;
}

void	ft_death(t_mlx_global *game)
{
	int	*rl;
	int	*du;

	rl = (int *)malloc(sizeof(int) * 3);
	du = (int *)malloc(sizeof(int) * 3);
	if (!rl || !du)
		return ;
	rl[0] = game->player_pos[1] + 1;
	rl[1] = game->player_pos[1] - 1;
	rl[2] = game->player_pos[0];
	du[0] = game->player_pos[0] + 1;
	du[1] = game->player_pos[0] - 1;
	du[2] = game->player_pos[1];
	game->map[du[0] - 1][rl[0] - 1] = 'X';
	cross_animation(game, rl, du);
	free(rl);
	free(du);
	wall_down(game);
	return ;
}

int	can_u_move(t_mlx_global *game, int x, int y)
{
	if (game->map[game->player_pos[0] + x][game->player_pos[1] + y] == 'X')
	{
		ft_death(game);
		exit_game(game);
	}
	if (game->map[game->player_pos[0] + x][game->player_pos[1] + y] == '0')
	{
		display_step_count(game);
		return (0);
	}
	if (game->map[game->player_pos[0] + x][game->player_pos[1] + y] == 'C')
	{
		display_step_count(game);
		game->c--;
		if (game->c == 0)
			draw_map(game);
		return (0);
	}
	if (game->map[game->player_pos[0] + x][game->player_pos[1] + y] == 'E'
		&& game->c == 0)
	{
		display_step_count(game);
		return (1);
	}
	return (-1);
}
