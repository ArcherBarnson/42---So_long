/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:58:59 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 11:06:04 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_bounds(t_mlx_global *game)
{
	int	i;
	int	len;

	i = 0;
	if (!game->map)
		return (-1);
	len = get_line_size(game->map[i]);
	while (game->map[i] != NULL)
	{
		if (len != get_line_size(game->map[i]))
			return (-1);
		if (check_wall(game, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	check_tiles(t_mlx_global *game)
{
	int	i;
	int	j;
	int	tile;

	i = -1;
	j = 0;
	while (game->map[++i] != NULL)
	{
		while (game->map[i][j] != '\n'
			&& game->map[i][j] != '\0')
		{
			tile = where_is_that_char(game->map[i][j], TILES);
			if (tile == -1)
				return (-1);
			if (tile == 2)
				game->p++;
			if (tile == 3)
				game->e++;
			if (tile == 4)
				game->c++;
			j++;
		}
		j = 0;
	}
	return (0);
}

int	check_special_tiles(t_mlx_global *game)
{
	if (game->p != 1)
		return (-5);
	if (game->c < 1)
		return (-6);
	if (game->e < 1)
		return (-7);
	return (0);
}

int	main_check(t_mlx_global *game)
{
	if (check_bounds(game) == -1)
		return (-3);
	if (check_tiles(game) == -1)
		return (-4);
	if (check_special_tiles(game) != 0)
		return (check_special_tiles(game));
	return (0);
}

int	ft_parsing(char *map_file, t_mlx_global *game)
{
	char	*tmpline;
	int		err_code;

	if (verify_extension(map_file) == -1)
		return (-2);
	game->map_fd = open(map_file, O_RDONLY, 0644);
	if (game->map_fd <= 0)
		return (-1);
	tmpline = get_next_line(game->map_fd);
	while (tmpline != NULL)
	{
		if (!game->map_line)
			game->map_line = ft_strdup(tmpline);
		game->map_line = cat_line(game->map_line, tmpline);
		game->map_line = cat_line(game->map_line, "|");
		free(tmpline);
		tmpline = get_next_line(game->map_fd);
	}
	free(tmpline);
	game->map = ft_split(game->map_line, '|');
	close(game->map_fd);
	err_code = main_check(game);
	if (err_code < 0)
		return (err_code);
	return (0);
}
