/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:04:54 by bgrulois          #+#    #+#             */
/*   Updated: 2021/11/25 15:05:38 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (n > 0 && s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)(s1[i]) > (unsigned char)(s2[i])
			|| (unsigned char)(s1[i]) < (unsigned char)(s2[i]))
			return ((unsigned char)(s1[i])
					- (unsigned char)(s2[i]));
		i++;
		n--;
	}
	if (n != 0 && (((unsigned char)(s2[i]) != '\0'
			&& (unsigned char)(s1[i]) == '\0')
			|| ((unsigned char)(s1[i]) != '\0'
				&& (unsigned char)(s2[i]) == '\0')))
		return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	return (0);
}
