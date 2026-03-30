/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cas_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:27:59 by atrombel          #+#    #+#             */
/*   Updated: 2025/12/09 19:35:07 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conversion(unsigned long long int g, int count)
{
	if (g > 15)
	{
		count = conversion(g / 16, count);
		g = g % 16;
	}
	count += 1;
	write(1, &HEXA[g], 1);
	return (count);
}

int	cas_pointer(void *addresse)
{
	unsigned long long int	g;
	int						count;

	g = (unsigned long long int)(addresse);
	if (addresse == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	count = 2;
	write(1, "0x", 2);
	return (conversion(g, count));
}
