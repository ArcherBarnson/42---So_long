/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:01:23 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/09 17:15:09 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_malloc_size(char *s1, char *s2)
{
	int	malloc_size;

	malloc_size = 0;
	if (s1 != NULL)
		malloc_size = ft_strlen(s1);
	if (s2 != NULL)
		malloc_size += ft_strlen(s2);
	return (malloc_size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*returnstr;
	int		malloc_size;
	int		i;
	int		j;

	i = -1;
	j = 0;
	malloc_size = get_malloc_size((char *)s1, (char *)s2);
	returnstr = malloc(sizeof(char) * (malloc_size) + 1);
	if (!(returnstr))
		return (NULL);
	while (s1 != NULL && s1[++i] != '\0')
	{
		returnstr[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2 != NULL && s2[++i] != '\0')
	{
		returnstr[j] = s2[i];
		j++;
	}
	returnstr[j] = '\0';
	return (returnstr);
}
