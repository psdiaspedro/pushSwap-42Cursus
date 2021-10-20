/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:45:54 by paugusto          #+#    #+#             */
/*   Updated: 2021/10/05 09:20:42 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_total;
	size_t	i;

	len_total = ft_strlen(src) + ft_strlen(dst);
	len_dst = ft_strlen(dst);
	i = 0;
	if (size < len_dst)
		return (ft_strlen(src) + size);
	while ((src[i] != '\0') && ((len_dst + 1) < size))
		dst[len_dst++] = src[i++];
	if (len_dst != size)
		dst[len_dst] = '\0';
	return (len_total);
}
