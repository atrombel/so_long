/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:07:13 by atrombel          #+#    #+#             */
/*   Updated: 2025/10/16 14:09:01 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		i++;
		while (s[i] && s[i] == c)
		{
			j++;
			if (s[i] && s[i + 1] == c)
				j--;
			i++;
		}
	}
	if (s[i - 1] == c)
		return (j);
	else
		j++;
	return (j);
}

static size_t	ft_premc(const char *s, size_t j, char c)
{
	while (s[j] && s[j] == c)
		j++;
	while (s[j] && s[j] != c)
		j++;
	return (j);
}

static void	ft_free(char **dest, size_t i)
{
	while (i > 0)
	{
		free(dest[--i]);
	}
	free(dest);
}

static int	ft_sep(size_t x, char **dest, char const *s, char c)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (s[j] && s[j] == c)
		j++;
	while (i < x)
	{
		dest[i] = ft_substr(s, j, (ft_premc(s, j, c) - j));
		if (!dest[i])
		{
			ft_free(dest, i);
			return (1);
		}
		j += ft_strlen(dest[i]) + 1;
		while (s[j] == c && s[j])
			j++;
		i++;
	}
	dest[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	x;
	size_t	j;

	j = 0;
	x = ft_count((char *)s, c);
	dest = malloc(sizeof(char *) * (x + 1));
	if (!dest)
		return (NULL);
	j = ft_sep(x, dest, s, c);
	if (j == 1)
	{
		dest = NULL;
		return (dest);
	}
	dest[x] = NULL;
	return (dest);
}
