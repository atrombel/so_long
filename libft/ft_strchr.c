/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:47:24 by atrombel          #+#    #+#             */
/*   Updated: 2025/10/16 14:05:24 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int					i;
	unsigned char		*p;
	unsigned char		l;

	l = c;
	p = (unsigned char *)s;
	i = 0;
	while (p[i] != l && p[i])
		i++;
	if (p[i] != l)
		return (NULL);
	p = &p[i];
	return ((char *)p);
}
