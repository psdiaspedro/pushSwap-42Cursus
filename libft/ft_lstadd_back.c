/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:06:21 by paugusto          #+#    #+#             */
/*   Updated: 2021/10/05 09:19:14 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*holder;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	holder = ft_lstlast(*lst);
	holder->next = new;
}
