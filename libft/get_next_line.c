/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:41:40 by atrombel          #+#    #+#             */
/*   Updated: 2025/11/26 19:36:25 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rmvn_gnl(char *stash, int g)
{
	int		n;
	char	*dst;

	n = 0;
	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	if ((g == -1 && stash[0] != '\0'))
		g = ft_strlen_gnl(stash);
	else
		g++;
	dst = (char *)malloc(g + 1);
	if (!dst)
		return (NULL);
	while (n < g)
	{
		dst[n] = stash[n];
		n++;
	}
	dst[n] = '\0';
	return (dst);
}

long	ft_ncount_gnl(char *stash)
{
	long	i;

	i = 0;
	if (stash == NULL)
		return (-1);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_line_gnl(int fd, char *temp, long g, ssize_t i)
{
	char		*dst;
	static char	*stash;

	while (i > 0 && g == -1)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (!i && !stash)
			return (NULL);
		if (i < 0 && stash)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (i > 0)
		{
			stash = ft_strjoin_gnl(stash, temp, i);
			g = ft_ncount_gnl(stash);
		}
		else
			g = ft_ncount_gnl(stash);
	}
	dst = ft_rmvn_gnl(stash, g);
	stash = ft_substr_gnl(stash, g);
	return (dst);
}

char	*get_next_line(int fd)
{
	char	*fin;
	char	*temp;
	long	g;
	ssize_t	i;

	i = 1;
	g = -1;
	fin = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	fin = ft_line_gnl(fd, temp, g, i);
	free (temp);
	return (fin);
}
