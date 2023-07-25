/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:23:02 by smeixoei          #+#    #+#             */
/*   Updated: 2023/06/12 14:43:33 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*follow;

	if (lst == NULL)
		return ;
	else
	{
		current = *lst;
		while (current != NULL)
		{
			follow = current->next;
			ft_lstdelone(current, del);
			current = follow;
		}
		*lst = NULL;
	}
}
