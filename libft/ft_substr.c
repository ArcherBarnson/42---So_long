/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:39:17 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/09 17:17:38 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*returnstr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen((char *)s))
		len = 0;
	if (len >= ft_strlen((char *)s))
		len = ft_strlen((char *)s) - start;
	returnstr = malloc(sizeof(char) * (len + 1));
	if (!(returnstr))
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		returnstr[i] = s[start];
		start++;
		i++;
	}
	returnstr[i] = '\0';
	return (returnstr);
}
