/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cas_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:17:07 by atrombel          #+#    #+#             */
/*   Updated: 2025/12/09 19:05:52 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_count(unsigned int n, int fd)
{
	long int	nbr;
	long int	count;

	count = 1;
	nbr = n;
	if (nbr > 9)
	{
		count += ft_putunbr_count(nbr / 10, fd);
		nbr = nbr % 10;
	}
	nbr = nbr + 48;
	write(fd, &nbr, 1);
	return (count);
}

int	cas_uint(unsigned int d, long int count)
{
	count = ft_putunbr_count(d, 1);
	return (count);
}
