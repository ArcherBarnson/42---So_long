/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:23:26 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/09 17:19:57 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cb;

	i = 0;
	cb = (unsigned char)c;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == cb)
			return (&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
