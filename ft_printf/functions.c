/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:42:20 by hguerrei          #+#    #+#             */
/*   Updated: 2024/05/03 14:42:44 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printbase(long nbr, int base, char *symbols)
{
	int	count;

	if (nbr < 0)
	{
		write(1, "-", 1);
		return (printbase(-nbr, base, symbols) + 1);
	}
	else if (nbr < base)
	{
		return (ft_putchar(symbols[nbr]));
	}
	else
	{
		count = printbase(nbr / base, base, symbols);
		return (count + printbase(nbr % base, base, symbols));
	}
}
