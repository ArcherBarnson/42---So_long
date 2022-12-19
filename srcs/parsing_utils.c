/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:59:11 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 10:03:04 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*cat_line(char *s1, char *s2)
{
	int		i;
	int		j;
	int		size;
	char	*rstr;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	rstr = (char *)malloc(sizeof(char) * size);
	if (!rstr)
		return (NULL);
	while (s1[++i])
		rstr[++j] = s1[i];
	i = -1;
	while (s2[++i])
		rstr[++j] = s2[i];
	rstr[j + 1] = '\0';
	if (s1)
		free(s1);
	return (rstr);
}

int	verify_extension(char *map_file)
{
	int	len;

	len = 0;
	if (!map_file)
		return (-1);
	while (map_file[len])
		len++;
	if (map_file[len - 4] == '.' && map_file[len - 3] == 'b'
		&& map_file[len - 2] == 'e' && map_file[len - 1] == 'r')
		return (0);
	return (-1);
}

int	where_is_that_char(char c, char	*str)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int	check_wall(t_mlx_global *game, int i)
{
	int	j;

	j = 0;
	if (i == 0 || game->map[i + 1] == NULL)
	{
		while (game->map[i][j] != '\n'
			&& game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '1')
				return (-1);
			j++;
		}
	}
	else
	{
		while (game->map[i][j] != '\n'
			&& game->map[i][j] != '\0')
			j++;
		if (game->map[i][0] != '1'
			|| game->map[i][j - 1] != '1')
			return (-1);
	}
	return (0);
}
