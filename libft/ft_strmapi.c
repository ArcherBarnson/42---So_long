/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:42:53 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/02 15:15:26 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*returnstr;

	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[len] != '\0')
		len++;
	returnstr = malloc(sizeof(char) * (len + 1));
	if (!returnstr)
		return (NULL);
	while (i < len)
	{
		returnstr[i] = (*f)(i, s[i]);
		i++;
	}
	returnstr[i] = '\0';
	return (returnstr);
}
