/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:40:15 by hguerrei          #+#    #+#             */
/*   Updated: 2024/05/09 13:11:05 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	printbase(long nbr, int base, char *symbols);
int	ft_putptr_base(unsigned long long ptr, char *base, int f);
int	ft_conversions(char format, va_list args);
int	ft_printf(const char *str, ...);
