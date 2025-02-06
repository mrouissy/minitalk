/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:50:30 by mrouissy          #+#    #+#             */
/*   Updated: 2024/11/08 18:16:44 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


static int	toprint(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		len += ft_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		len += ft_hexa(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		len += ft_hexa(va_arg(args, unsigned long), 'X');
	else if (c == 'p')
		len += ft_printad(va_arg(args, void *));
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!string)
		return (-1);
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			if (string[i + 1] == '\0')
				return (-1);
			len += toprint(args, string[i + 1]);
			i++;
		}
		else
			len += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (len);
}

