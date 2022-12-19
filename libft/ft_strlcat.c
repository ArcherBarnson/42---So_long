/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:11:48 by bgrulois          #+#    #+#             */
/*   Updated: 2021/11/25 15:06:54 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	unsigned int	len;
	unsigned int	j;

	len = 0;
	j = 0;
	while (dest[len] != '\0')
		len++;
	while (j < nb && src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';
	return (dest);
}

size_t	ft_strlcat(char	*dest, const char *src, size_t size)
{
	unsigned int	lensrc;
	unsigned int	lendest;

	lensrc = ft_strlen((char *)src);
	lendest = ft_strlen(dest);
	if (size <= lendest)
		return (size + lensrc);
	ft_strncat(dest, src, size - lendest - 1);
	return ((size_t)(lensrc + lendest));
}
