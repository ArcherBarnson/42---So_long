/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:53:21 by bgrulois          #+#    #+#             */
/*   Updated: 2021/11/30 14:43:44 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!s)
		return ;
	while (s[len] != '\0')
		len++;
	while (i < len)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
