/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:38:52 by atrombel          #+#    #+#             */
/*   Updated: 2025/10/16 14:03:12 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rempl(char *d, long nlen, long n)
{
	while (nlen >= 0)
	{
		d[nlen] = ((n % 10) + 48);
		n = n / 10;
		nlen--;
	}
}

static int	ft_nbrlen(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long		nlen;
	long		sgn;
	char		*dest;
	long		p;

	p = n;
	sgn = 1;
	nlen = 0;
	if (p < 0)
	{
		sgn = -1;
		p *= -1;
		nlen++;
	}
	nlen += ft_nbrlen(p);
	dest = malloc(sizeof(char) * (nlen + 1));
	if (!dest)
		return (NULL);
	dest[nlen] = '\0';
	nlen--;
	ft_rempl(dest, nlen, p);
	if (sgn == -1)
		dest[0] = '-';
	return (dest);
}
