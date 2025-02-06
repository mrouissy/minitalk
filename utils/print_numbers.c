/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:30:58 by mrouissy          #+#    #+#             */
/*   Updated: 2024/11/08 15:03:21 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putnbr(int n)
{
	long	num;
	int		len;
	char	nbr[12];
	int		i;

	num = (long)n;
	len = 0;
	i = 0;
	if (num < 0)
	{
		len += write(1, "-", 1);
		num = -num;
	}
	if (num == 0)
		len += write(1, "0", 1);
	while (num > 0)
	{
		nbr[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (--i >= 0)
		len += write(1, &nbr[i], 1);
	return (len);
}

int	ft_unsigned(unsigned int n)
{
	int					i;
	int					len;
	unsigned long long	num;
	char				nbr[12];

	num = (unsigned long long)n;
	len = 0;
	i = 0;
	if (num == 0)
		nbr[i++] = 48;
	while (num > 0)
	{
		nbr[i++] = (num % 10) + 48;
		num /= 10;
	}
	while (--i >= 0)
		len += write(1, &nbr[i], 1);
	return (len);
}
