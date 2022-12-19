/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:59:40 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 09:59:42 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	unset_assets_paths(t_mlx_global *game)
{
	int	i;

	i = -1;
	while (++i < 12)
		free(game->sprites->paths[i]);
	return ;
}

void	set_assets_paths(t_mlx_global *game)
{
	game->sprites->paths[0] = ft_strjoin(game->spd, "/E0.xpm");
	game->sprites->paths[1] = ft_strjoin(game->spd, "/E1.xpm");
	game->sprites->paths[2] = ft_strjoin(game->spd, "/E2.xpm");
	game->sprites->paths[3] = ft_strjoin(game->spd, "/C0.xpm");
	game->sprites->paths[4] = ft_strjoin(game->spd, "/C1.xpm");
	game->sprites->paths[5] = ft_strjoin(game->spd, "/C2.xpm");
	game->sprites->paths[6] = ft_strjoin(game->spd, "/P0.xpm");
	game->sprites->paths[7] = ft_strjoin(game->spd, "/P1.xpm");
	game->sprites->paths[8] = ft_strjoin(game->spd, "/X0.xpm");
	game->sprites->paths[9] = ft_strjoin(game->spd, "/X1.xpm");
	game->sprites->paths[10] = ft_strjoin(game->spd, "/FL.xpm");
	game->sprites->paths[11] = ft_strjoin(game->spd, "/WA.xpm");
	return ;
}

t_data	*load_asset(t_mlx_global *game, void *asset, int i)
{
	asset = mlx_xpm_file_to_image(game->mlx, game->sprites->paths[i],
			&game->sprites->img_width, &game->sprites->img_height);
	if (!asset)
		return (NULL);
	return (asset);
}

int	check_sprites_integrity(t_mlx_global *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->sprites->collectible[i] == NULL
			|| game->sprites->player[i] == NULL)
			return (-1);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (game->sprites->exit[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}

int	load_sprites(t_mlx_global *game)
{
	int	i;

	i = 2;
	set_assets_paths(game);
	while (++i < 6)
		game->sprites->collectible[i - 3] = load_asset(game,
				game->sprites->collectible[i - 3], i);
	while (i < 8)
	{
		game->sprites->player[i - 6] = load_asset(game,
				game->sprites->player[i - 6], i);
		i++;
	}
	while (i < 10)
	{
		game->sprites->exit[i - 8] = load_asset(game,
				game->sprites->exit[i - 8], i);
		i++;
	}
	game->sprites->ground = load_asset(game, game->sprites->ground, i);
	game->sprites->wall = load_asset(game, game->sprites->wall, i + 1);
	game->sprites->player[2] = load_asset(game,
			game->sprites->player[2], 6);
	return (check_sprites_integrity(game));
}
