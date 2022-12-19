/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:04:01 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 10:08:39 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	*generate_random_coordinates(int x, int y)
{
	int		*rcords;
	char	urand[2];
	int		urand_fd;
	int		i;

	rcords = malloc(sizeof(int) * 2);
	if (!rcords)
		return (NULL);
	i = 0;
	urand_fd = open("/dev/urandom", O_RDONLY, 0644);
	read(urand_fd, urand, 2);
	close(urand_fd);
	while (i < 2)
	{
		rcords[i] = (int)urand[i];
		if (rcords[i] < 0)
			rcords[i] = -rcords[i];
		if (i == 0)
			rcords[i] = (rcords[i] + 1) % x;
		if (i == 1)
			rcords[i] = (rcords[i] + 1) % y;
		i++;
	}
	return (rcords);
}

void	place_ennemies(t_mlx_global *game)
{
	int	cols;
	int	rows;
	int	rec;
	int	*rcords;

	cols = game->map_dimensions[0] / game->sps;
	rows = game->map_dimensions[1] / game->sps;
	rec = game->ennemy_count;
	rcords = generate_random_coordinates(cols, rows);
	while (rec > 0)
	{
		if ((rcords[0] < cols - 1 && rcords[1] < rows -1)
			&& game->map[rcords[1]][rcords[0]] == '0')
		{
			game->map[rcords[1]][rcords[0]] = 'X';
			rec--;
		}
		free(rcords);
		rcords = generate_random_coordinates(cols, rows);
	}
	free(rcords);
	return ;
}

int	count_available_tiles(t_mlx_global *game)
{
	int	i;
	int	j;
	int	available_tiles;

	i = 0;
	j = 0;
	available_tiles = 0;
	while (game->map[i] != NULL)
	{
		while (game->map[i][j] != '\n'
			&& game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '0')
				available_tiles++;
			j++;
		}
		j = 0;
		i++;
	}
	return (available_tiles);
}

int	load_ennemies(t_mlx_global *game)
{
	int	i;

	i = 0;
	game->ennemy_count = count_available_tiles(game) / RATIO;
	while (i < 3)
	{
		game->sprites->ennemy[i]
			= load_asset(game, game->sprites->ennemy, i);
		if (game->sprites->ennemy[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_respawn(t_mlx_global *game)
{
	replace_tiles(game, 'X', '0', game->sprites->ground);
	place_ennemies(game);
	replace_tiles(game, 'X', 'X', game->sprites->ennemy[0]);
	return ;
}
