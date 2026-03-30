/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cas_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:43:34 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/15 10:30:19 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_putnbr_count(long n, int fd)
{
	long int	nbr;
	long int	count;

	count = 1;
	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		return (ft_putnbr_count(-n, fd) + 1);
	}
	if (nbr > 9)
	{
		count += ft_putnbr_count(nbr / 10, fd);
		nbr = nbr % 10;
	}
	nbr = nbr + 48;
	write(fd, &nbr, 1);
	return (count);
}

int	cas_int(long d, int count)
{
	count = ft_putnbr_count(d, 1);
	return (count);
}
