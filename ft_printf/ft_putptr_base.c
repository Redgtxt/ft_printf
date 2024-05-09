/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei < hguerrei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:41:45 by hguerrei          #+#    #+#             */
/*   Updated: 2024/05/09 14:23:12 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_base(unsigned long long ptr, char *base, int f)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		return (write(1, "(nil)", 5));
	}
	if (f == 0)
	{
		write(1, "0x", 2);
		count += 2;
	}
	if (ptr / 16 > 0)
	{
		count += ft_putptr_base((ptr / 16), base, 1);
	}
	ft_putchar(base[ptr % 16]);
	count++;
	return (count);
}
