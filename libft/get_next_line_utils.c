/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:28:06 by atrombel          #+#    #+#             */
/*   Updated: 2025/11/26 19:40:15 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_lien_gnl(size_t	i, char *d, char *s)
{
	long	j;
	long	len;

	len = ft_strlen_gnl(s);
	j = 0;
	while (j < len)
	{
		d[i] = s[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, ssize_t x)
{
	size_t	i;
	char	*dest;

	i = 0;
	s2[x] = '\0';
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (s1);
	dest = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!dest)
		return (NULL);
	i = ft_lien_gnl(i, dest, s1);
	i = ft_lien_gnl(i, dest, s2);
	free(s1);
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup_gnl(char *s)
{
	char	*dup;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	j = ft_strlen_gnl(s);
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

char	*ft_substr_gnl(char *stash, int g)
{
	int		len;
	char	*str;
	int		a;

	if (!stash)
		return (NULL);
	len = ft_strlen_gnl(stash);
	if ((g == -1
			|| (stash[g] == '\n' && g == 0 && stash[g + 1] == '\0')))
		return (free(stash), NULL);
	if (stash[g] == '\n')
		g += 1;
	if (stash[g] == '\0')
		return (free(stash), NULL);
	str = (char *)malloc(len - g + 1);
	if (!str)
		return (NULL);
	a = 0;
	while (g < len && stash[g])
		str[a++] = stash[g++];
	str[a] = '\0';
	return (free(stash), str);
}
