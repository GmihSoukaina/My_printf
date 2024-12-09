/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:02:09 by sgmih             #+#    #+#             */
/*   Updated: 2024/12/09 11:33:57 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char chr, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_putunsgned(unsigned int nbr, int *len);
void	ft_puthexa(unsigned int nbr, char hex, int *len);
void	ft_putadrs(unsigned long nbr, char hex, int *len);
int		ft_printf(const char *str, ...);

#endif