/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:08:34 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/09 17:18:33 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *)(str));
	while (i < len && str[i] != '\0')
	{
		if ((unsigned char)(to_find[0]) == (unsigned char)(str[i]))
		{
			while ((unsigned char)(to_find[j]) == (unsigned char)(str[i])
					&& i < len && to_find[j] != '\0')
			{
				i++;
				j++;
			}
		}
		if (to_find[j] == '\0')
			return ((char *)(&str[i - j]));
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
