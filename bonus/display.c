/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:03:53 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 10:15:31 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	replace_last_line(t_mlx_global *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != NULL)
		i++;
	while (game->map[i - 1][j] != '\0' && game->map[i - 1][j] != '\n')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall, j * game->sps, (i - 1) * game->sps);
		j++;
	}
	return ;
}

void	display_step_count(t_mlx_global *game)
{
	char	*sc;
	char	*str;

	replace_last_line(game);
	sc = ft_itoa(game->step_count);
	str = ft_strjoin("STEPS : ", sc);
	free(sc);
	mlx_string_put(game->mlx, game->window,
		game->map_dimensions[0] / 2 - game->sps,
		game->map_dimensions[1] - (game->sps / 2),
		16777215, str);
	free(str);
	return ;
}

char	*get_sprite_dir(t_mlx_global *game, int x, int y)
{
	char	*returnstr;

	returnstr = NULL;
	if (game->map_dimensions[0] * LARGE < y
		&& game->map_dimensions[1] * LARGE < x)
		returnstr = ft_strdup(L_DIR);
	else if (game->map_dimensions[0] * MEDIUM < y
		&& game->map_dimensions[1] * MEDIUM < x)
		returnstr = ft_strdup(M_DIR);
	else if (game->map_dimensions[0] * SMALL < y
		&& game->map_dimensions[1] * SMALL < x)
		returnstr = ft_strdup(S_DIR);
	return (returnstr);
}

int	choose_res(t_mlx_global *game, int x, int y)
{
	int	size;

	size = 0;
	if (game->map_dimensions[0] * LARGE < y
		&& game->map_dimensions[1] * LARGE < x)
		size = LARGE;
	else if (game->map_dimensions[0] * MEDIUM < y
		&& game->map_dimensions[1] * MEDIUM < x)
		size = MEDIUM;
	else if (game->map_dimensions[0] * SMALL < y
		&& game->map_dimensions[1] * SMALL < x)
		size = SMALL;
	return (size);
}

int	detect_res(t_mlx_global *game)
{
	int	x;
	int	y;

	x = 2560;
	y = 1440;
	game->sps = choose_res(game, x, y);
	game->spd = get_sprite_dir(game, x, y);
	if (game->sps == 0 || game->spd == NULL)
		return (-1);
	game->map_dimensions[0] *= game->sps;
	game->map_dimensions[1] *= game->sps;
	return (0);
}
