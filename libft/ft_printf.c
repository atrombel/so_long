/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:48:21 by atrombel          #+#    #+#             */
/*   Updated: 2026/02/02 18:29:47 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start (args, format);
	i = 0;
	count = 0;
	if (!format)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += ft_pourcent((char *)format, i, args);
			i += 1;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
