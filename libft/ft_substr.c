/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 23:34:37 by paugusto          #+#    #+#             */
/*   Updated: 2021/10/30 18:40:54 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;
	unsigned int	slen;

	if (!s)
		return (NULL);
	i = 0;
	j = start;
	slen = ft_strlen(s);
	if (((slen - start) > len) && (start < slen))
		sub = malloc((len * sizeof(char) + 1));
	else if (start > slen)
		sub = malloc(sizeof(char));
	else
		sub = malloc(((slen - start) * sizeof(char) + 1));
	if (!sub)
		return (NULL);
	if ((start < slen))
	{
		while ((i < len) && s[j])
			sub[i++] = s[j++];
	}
	sub[i] = '\0';
	return (sub);
}
