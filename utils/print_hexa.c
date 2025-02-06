/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:42:35 by mrouissy          #+#    #+#             */
/*   Updated: 2024/11/08 14:54:20 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int n, char format)
{
	int				count;
	char			*hnum;

	if (format == 'X')
		hnum = "0123456789ABCDEF";
	else
		hnum = "0123456789abcdef";
	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n >= 16)
		count += ft_hexa(n / 16, format);
	count += ft_putchar(hnum[n % 16]);
	return (count);
}

int	ft_ptrhexa(unsigned long n)
{
	int				count;
	char			*hnum;

	hnum = "0123456789abcdef";
	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n >= 16)
		count += ft_ptrhexa(n / 16);
	count += ft_putchar(hnum[n % 16]);
	return (count);
}

int	ft_printad(void *p)
{
	int				count;
	unsigned long	adr;

	adr = (unsigned long)p;
	count = 0;
	if (p == 0)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_ptrhexa(adr);
	return (count);
}
