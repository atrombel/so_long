/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:00:23 by atrombel          #+#    #+#             */
/*   Updated: 2025/10/16 14:24:07 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		l;
	const char	*mem;
	size_t		x;

	i = 0;
	if (ft_strlen(little) == 0 || big == little)
		return ((char *)big);
	while (i < len && big[i])
	{
		l = 0;
		x = 0;
		mem = &big[i];
		while ((big[i + x] == little[l]) && (i + x) < len)
		{
			x++;
			l++;
			if (l == (ft_strlen(little)))
				return ((char *)mem);
		}
		i++;
	}
	return (0);
}
