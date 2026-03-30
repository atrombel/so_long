/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:21:34 by atrombel          #+#    #+#             */
/*   Updated: 2025/10/16 14:13:25 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*p;
	unsigned char	l;

	l = c;
	i = ft_strlen(s);
	while (s[i] != l && i > 0)
		i--;
	if (s[i] != l)
		return (NULL);
	p = (char *)&s[i];
	return (p);
}
