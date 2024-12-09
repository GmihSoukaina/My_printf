/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:34:41 by sgmih             #+#    #+#             */
/*   Updated: 2024/12/09 11:33:18 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_puthexa(unsigned int nbr, char hex, int *len)
{
	char	*base;

	if (hex == 'x')
		base = "0123456789abcdef";
	else if (hex == 'X')
		base = "0123456789ABCDEF";
	if (nbr > 15)
	{
		ft_puthexa((nbr / 16), hex, len);
		ft_puthexa((nbr % 16), hex, len);
	}
	else
		ft_putchar(base[nbr], len);
}
