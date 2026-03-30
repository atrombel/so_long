/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:41:40 by atrombel          #+#    #+#             */
/*   Updated: 2025/10/16 14:12:08 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		j;

	j = ft_strlen(s);
	i = 0;
	dup = malloc(sizeof(char) * (j + 1));
	if (!dup)
		return (0);
	while (i <= j)
	{
		dup[i] = ((unsigned char *)s)[i];
		i++;
	}
	return (dup);
}
