/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:50:33 by sgmih             #+#    #+#             */
/*   Updated: 2024/12/11 09:10:39 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	flg_check(char c)
{
	if (c == '#' || c == '+' || c == ' ')
		return (1);
	return (0);
}

static void	ft_check(char c, va_list arg, int *len, int flg)
{
	int	n;

	if (c == 'c')
		ft_putchar((char)va_arg(arg, int), len);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (c == 'p')
	{
		ft_putstr("0x", len);
		ft_putadrs(va_arg(arg, unsigned long), c, len);
	}
	else if (c == 'i' || c == 'd')
	{
		n = va_arg(arg, int);
		if (flg == '+' && n >= 0)
			ft_putchar('+', len);
		else if (flg == ' ' && n >= 0)
			ft_putchar(' ', len);
		ft_putnbr(n, len);
	}
	else if (c == 'u')
		ft_putunsgned(va_arg(arg, unsigned int), len);
	else if (c == 'x' || c == 'X')
	{
		if (flg)
		{
			if (c == 'x')
				ft_putstr("0x", len);
			else if (c == 'X')
				ft_putstr("0X", len);
		}
		ft_puthexa(va_arg(arg, unsigned int), c, len);
	}
	else if (c == '%')
		ft_putchar(c, len);
	else
		ft_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		i;
	int		flg;

	len = 0;
	i = 0;
	flg = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			while (str[i] == '#' || str[i] == '+' || str[i] == ' ')
			{
				flg = str[i];
				i++;
			}
			ft_check(str[i], arg, &len, flg);
			flg = 0;
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(arg);
	return (len);
}

