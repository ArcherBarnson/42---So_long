/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:45:38 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/09 17:17:29 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_to_trim(char const c, char const *set)
{
	int	j;

	j = 0;
	while (set[j] != '\0' && set != NULL)
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

static int	malloc_get_size(char const *s1, char const *set)
{
	int	malloc_size;
	int	i;
	int	j;

	malloc_size = 1;
	if (set == NULL)
	{
		malloc_size = ft_strlen((char *)s1) + 1;
		return (malloc_size);
	}
	i = 0;
	j = ft_strlen((char *)s1) - 1;
	while (is_to_trim(s1[i], set) == 1)
		i++;
	while (is_to_trim(s1[j], set) == 1)
		j--;
	malloc_size = malloc_size + (j - i) + 1;
	if (malloc_size <= 0)
		malloc_size = 1;
	return (malloc_size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*returnstr;

	i = 0;
	k = 0;
	if (s1 == NULL)
		return (NULL);
	returnstr = malloc(sizeof(char) * (malloc_get_size(s1, set)));
	if (!(returnstr))
		return (NULL);
	j = ft_strlen((char *) s1) - 1;
	while (is_to_trim(s1[i], set) == 1)
		i++;
	while (is_to_trim(s1[j], set) != 0)
		j--;
	while (i <= j)
	{
		returnstr[k] = s1[i];
		k++;
		i++;
	}
	returnstr[k] = '\0';
	return (returnstr);
}
