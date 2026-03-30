/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:53:39 by atrombel          #+#    #+#             */
/*   Updated: 2025/10/16 14:10:32 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tri(char s1, char const *rmv)
{
	size_t	j;

	j = 0;
	while (rmv[j])
	{
		if (rmv[j] == s1)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	l1;
	size_t	end;

	l1 = ft_strlen(s1);
	if (!s1)
		return (0);
	end = l1;
	start = 0;
	while (ft_tri(s1[start], set))
		start ++;
	if (start == l1)
		return (ft_strdup(""));
	while (ft_tri(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
