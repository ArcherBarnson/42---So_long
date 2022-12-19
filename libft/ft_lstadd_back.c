/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:00:10 by bgrulois          #+#    #+#             */
/*   Updated: 2021/12/06 20:13:19 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pos;

	pos = NULL;
	if (!lst || !new)
		return ;
	pos = *lst;
	if (!pos)
	{
		*lst = new;
		return ;
	}
	while (pos->next)
		pos = pos->next;
	pos->next = new;
}
