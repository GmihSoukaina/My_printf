/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:34:41 by sgmih             #+#    #+#             */
/*   Updated: 2024/12/05 21:12:35 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int nbr, char hex, int *len)
{
	char	*base;

	if (hex == 'x')
		base = "0123456789abcdef";
	else if (hex == 'X')
		base = "0123456789ABCDEF";
	if (nbr > 15)
	{
		ft_putchar((nbr / 16), len);
		ft_putchar((nbr % 16), len);
	}
	else
		ft_putchar(base[nbr], len);
}
