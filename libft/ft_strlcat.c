/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:40:16 by atrombel          #+#    #+#             */
/*   Updated: 2025/10/16 14:23:45 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;
	size_t	p;

	i = 0;
	l = ft_strlen(dst);
	p = ft_strlen(src);
	if ((size) <= l)
		return (p + size);
	while (src[i] && i < (size - l - 1))
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[i + l] = '\0';
	return (l + p);
}
