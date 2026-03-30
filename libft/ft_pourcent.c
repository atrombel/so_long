/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:08:34 by atrombel          #+#    #+#             */
/*   Updated: 2025/12/09 19:29:44 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cas_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	cas_string(char *s)
{
	int	j;

	if (!s)
		s = "(null)";
	j = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (j);
}

int	ft_pourcent(char *format, int i, va_list args2)
{
	if (format[i + 1] == 'c')
		return (cas_char((unsigned char)va_arg(args2, int)));
	else if (format[i + 1] == 's')
		return (cas_string(va_arg(args2, void *)));
	else if (format[i + 1] == 'p')
		return (cas_pointer(va_arg(args2, void *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (cas_int(va_arg(args2, int), 0));
	else if (format[i + 1] == 'u')
		return ((cas_uint(va_arg(args2, int), 0)));
	else if (format[i + 1] == 'x')
		return ((cas_x(va_arg(args2, long), 0)));
	else if (format[i + 1] == 'X')
		return ((cas_xup(va_arg(args2, long), 0)));
	else if (format[i + 1] == '%')
		return (cas_prct(format[i]));
	return (0);
}
