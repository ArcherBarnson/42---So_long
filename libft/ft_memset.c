/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:33:08 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/02 12:15:33 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*sb;
	size_t			i;

	i = 0;
	sb = (unsigned char *)s;
	while (i < n)
	{
		sb[i] = c;
		i++;
	}
	return (sb);
}
