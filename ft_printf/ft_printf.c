/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei < hguerrei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:14:25 by hguerrei          #+#    #+#             */
/*   Updated: 2024/05/09 14:22:58 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(char format, va_list args)
{
	int	count;

	count = 0;

		if (format == 'c')
			count += ft_putchar(va_arg(args, int));
		else if (format == 's')
			count += ft_putstr(va_arg(args, char *));
		else if (format == 'p')
			count += ft_putptr_base(va_arg(args, unsigned long), "0123456789abcdef",
					0);
		else if (format == 'd' || format == 'i')
			count += printbase(va_arg(args, int), 10, "0123456789");
		else if (format == 'u')
			count += printbase(va_arg(args, unsigned int), 10, "0123456789");
		else if (format == 'x')
			count += printbase(va_arg(args, unsigned int), 16, "0123456789abcdef");
		else if (format == 'X')
			count += printbase(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
		else if (format == '%')
			count += ft_putchar('%');

	return (count);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	args;
	int		count;

	count = 0;
	i = -1;
	if(str == NULL)
		return (-1);
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
				count += ft_conversions(str[i + 1], args);
				i++;
		}
		else
			count += ft_putchar(str[i]);
	}
	va_end(args);
	return (count);
}

// int main()
// {
// 	ft_printf("%d\n",ft_printf("%%"));
// }
// #include <limits.h>
//  int	main(void)
// {
// 	int teste = printf("hello world\n");
// 	printf("imprimiu: %d\n", teste);
// 	int teste2 = ft_printf("hello world\n");
// 	ft_printf("imprimiu: %d\n", teste2);
// 	printf("\n");
// 	int x = 42;
// 	int x2 = 34;
// 	void *ptrx2 = &x2;
// 	void *ptr = &x;


// 	ft_printf("HELLO\n");
// 	ft_printf("%d \n", ft_printf(""));
// 	ft_printf("%d \n", ft_printf(NULL));
// 	ft_printf("CHARACTERS: %c %c\n", 'a', 'b');
// 	ft_printf("STRINGS: %s %s\n", "Good", "bye");
// 	ft_printf("DECIMAL: %i %d\n", 42, 123);
// 	ft_printf ("DECIMALS: %d %d\n", 1977, 650000L);
// 	ft_printf("POINTER NULO: %p \n", NULL );
// 	ft_printf("POINTER DE x é: %p\n", ptr);
// 	ft_printf("POINTER 0: %p %p \n", (void *)0, (void *)0);
// 	ft_printf ("DECIMAL e HEXADECIMAL: %d %x %X \n", 255, 255, 255);
// 	ft_printf ("HEXADECIMAL 0: %x %X\n", 0, 0);
// 	ft_printf ("Unsigned int: %u %u\n",  2147483647, UINT_MAX);
// 	ft_printf ("Unsigned int: %u \n", UINT_MAX);
// 	ft_printf ("Mix: %c, %s, %p, %d, %i, %x, %X, %u, %%, all mixed\n", 'A',
// 		"Mix", ptrx2, 34, 34, 255, 255, UINT_MAX);


// 	ft_printf("\n");

// 	printf("Hello\n");
// 	printf("%d \n", printf(""));
// 	printf("%d \n", printf(NULL));
// 	printf("Characters: %c %c\n", 'a', 'b');
// 	printf("Strings: %s %s\n", "Good", "bye");
// 	printf("Decimal: %d %d\n", 42, 123);
// 	printf ("Decimals: %d %ld\n", 1977, 650000L);
// 	printf("Pointer nulo: %p \n", NULL );
// 	printf("Pointer de x é: %p\n", ptr);
// 	printf("Pointer 0: %p %p \n", (void *)0, (void *)0);
// 	printf ("Decimal e hexadecimal: %d %x %X \n", 255, 255, 255);
// 	printf (" Hexadecimal 0: %x %X\n", 0, 0);
// 	printf ("Unsigned int: %u %u\n", 2147483647, UINT_MAX);
// 	printf ("Unsigned int: %u \n", UINT_MAX);
// 	printf ("Mix: %c, %s, %p, %d, %i, %x, %X, %u, %%, all mixed\n", 'A', "Mix",
// 		ptrx2, 34, 34, 255, 255, UINT_MAX);
// 	return (0);
// }
