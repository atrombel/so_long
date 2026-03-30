/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cas_xup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:18:09 by atrombel          #+#    #+#             */
/*   Updated: 2025/12/09 19:33:28 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cas_xup(unsigned int g, long count)
{
	count = 1;
	if (g > 15)
	{
		count += cas_xup(g / 16, 1);
		g = g % 16;
	}
	write(1, &HEXA_UP[g], 1);
	return (count);
}
