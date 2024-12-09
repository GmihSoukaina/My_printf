/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:50:33 by sgmih             #+#    #+#             */
/*   Updated: 2024/12/09 11:33:01 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static	void	ft_check(char c, va_list arg, int *len)
{
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
		ft_putnbr(va_arg(arg, int), len);
	else if (c == 'u')
		ft_putunsgned(va_arg(arg, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_puthexa(va_arg(arg, unsigned int), c, len);
	else if (c == '%')
		ft_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			ft_check(str[i], arg, &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end (arg);
	return (len);
}
