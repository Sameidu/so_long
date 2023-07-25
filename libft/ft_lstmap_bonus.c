/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:23:38 by smeixoei          #+#    #+#             */
/*   Updated: 2023/06/12 14:51:03 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final_list;

	if (lst == NULL)
		return (NULL);
	final_list = ft_lstnew(f(lst->content));
	if (final_list == NULL)
		ft_lstdelone(final_list, del);
	final_list->next = ft_lstmap(lst->next, f, del);
	return (final_list);
}
