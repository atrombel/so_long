/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:16:18 by atrombel          #+#    #+#             */
/*   Updated: 2025/10/16 14:03:36 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s[i] == d[i])
	{
		if (s[i] != d[i])
			return (s[i] - d[i]);
		i++;
		if (i == n)
			return ((s[i - 1] - d[i - 1]));
	}
	return (s[i] - d[i]);
}
