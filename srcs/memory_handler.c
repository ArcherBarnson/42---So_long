/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:58:48 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 09:58:50 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(void **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

void	free_sprite_lists(t_mlx_global *game)
{
	free(game->sprites->ennemy);
	free(game->sprites->collectible);
	free(game->sprites->player);
	free(game->sprites->exit);
	return ;
}

void	free_sprites(t_mlx_global *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->sprites->ground);
	mlx_destroy_image(game->mlx, game->sprites->wall);
	while (i < 2)
	{
		mlx_destroy_image(game->mlx, game->sprites->collectible[i]);
		mlx_destroy_image(game->mlx, game->sprites->player[i]);
		mlx_destroy_image(game->mlx, game->sprites->exit[i]);
		i++;
	}
	mlx_destroy_image(game->mlx, game->sprites->collectible[i]);
	mlx_destroy_image(game->mlx, game->sprites->player[i]);
	free_sprite_lists(game);
	return ;
}

void	free_game(t_mlx_global *game)
{
	int	i;

	i = 0;
	while (game->map && game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game->ennemypos);
	free(game->map_line);
	free(game->spd);
	return ;
}

void	exit_game(t_mlx_global *game)
{
	free_sprites(game);
	unset_assets_paths(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->sprites);
	free_game(game);
	free(game->mlx);
	free(game);
	exit(0);
	return ;
}
