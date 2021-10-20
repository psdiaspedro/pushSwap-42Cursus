/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 09:34:33 by paugusto          #+#    #+#             */
/*   Updated: 2021/10/05 09:20:55 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s1;
	if (ft_strlen(s2) == 0)
		return (p);
	while (p[i] != '\0' && n >= ft_strlen(s2))
	{
		if (ft_strncmp(&p[i], s2, ft_strlen(s2)) == 0)
		{
			if (ft_strlen(s2) > n)
				return (NULL);
			return (&p[i]);
		}
		n--;
		i++;
	}
	return (NULL);
}
