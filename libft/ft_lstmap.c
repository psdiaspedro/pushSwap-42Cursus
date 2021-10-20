/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:12:16 by paugusto          #+#    #+#             */
/*   Updated: 2021/10/05 09:19:42 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*item;

	if (!lst)
		return (0);
	new = NULL;
	while (lst != NULL)
	{
		item = ft_lstnew(f(lst->content));
		if (!item)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, item);
		lst = lst->next;
	}
	return (new);
}
