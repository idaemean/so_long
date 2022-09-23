/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:10:34 by iczarnie          #+#    #+#             */
/*   Updated: 2021/12/11 21:10:34 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*returned;
	t_list	*list;

	if (!del || !f || !lst)
		return (NULL);
	list = ft_lstnew(f(lst->content));
	if (!list)
		return (NULL);
	returned = list;
	lst = lst->next;
	while (lst)
	{
		list->next = ft_lstnew(f(lst->content));
		if (!list->next)
		{
			ft_lstclear(&returned, del);
			return (NULL);
		}
		list = list->next;
		lst = lst->next;
	}
	list->next = NULL;
	return (returned);
}
