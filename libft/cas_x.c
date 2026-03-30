/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cas_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:23:19 by atrombel          #+#    #+#             */
/*   Updated: 2025/12/09 19:24:48 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cas_x(unsigned int g, int count)
{
	count = 1;
	if (g > 15)
	{
		count += cas_x(g / 16, 1);
		g = g % 16;
	}
	write(1, &HEXA[g], 1);
	return (count);
}
