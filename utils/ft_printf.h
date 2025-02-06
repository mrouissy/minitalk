/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfH.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:52:00 by mrouissy          #+#    #+#             */
/*   Updated: 2024/11/08 15:02:41 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *string, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_unsigned(unsigned int n);
int	ft_hexa(unsigned int n, char format);
int	ft_printad(void *p);
void decrypt(int sig);
