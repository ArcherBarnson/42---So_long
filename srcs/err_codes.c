/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_codes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:58:02 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 10:56:58 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	err_msg(int err_code, t_mlx_global *game)
{
	write(2, "Error\n", 6);
	if (err_code == -1)
		write(2, "File not found. Check permissions or spelling !\n", 49);
	if (err_code == 0)
		write(2, "Usage : ./so_long <map.ber>\n", 28);
	if (err_code == -2)
		write(2, "Bad extension\n", 14);
	if (err_code == -3)
		write(2, "Bad map (not closed or wrong dimensions)\n", 41);
	if (err_code == -4)
		write(2, "Your map contains an invalid tile\n", 34);
	if (err_code == -5)
		write(2, "Invalid number of players\n", 26);
	if (err_code == -6)
		write(2, "No collectible present\n", 23);
	if (err_code == -7)
		write(2, "No exit present\n", 16);
	if (game)
	{
		free_sprite_lists(game);
		free(game->sprites);
		free_game(game);
		free(game);
	}
	return (-1);
}

void	mlx_error(t_mlx_global *game)
{
	write(2, "Error\nMlx initialization failed. Better luck next time !\n", 57);
	free_sprite_lists(game);
	free(game->sprites);
	free_game(game);
	free(game);
	exit(-1);
	return ;
}

void	sprite_error(t_mlx_global *game)
{
	unset_assets_paths(game);
	write(2, "Error\nAssets not found. Exiting\n", 32);
	free_sprite_lists(game);
	free(game->sprites);
	mlx_destroy_display(game->mlx);
	free_game(game);
	free(game->mlx);
	free(game->window);
	free(game);
	exit(0);
	return ;
}
