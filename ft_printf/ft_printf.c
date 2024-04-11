#include "ft_printf.h"

int	ft_conversions(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (*format == 's')
				ft_putstr_fd(va_arg(args, char *),1);
			else if(*format == 'p')
				return 0;
			else if(*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(args,int),1);
			else if(*format == 'u')
				return 1;

		}
		format++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	char	c;
	char	f;
	char	nome[] = "Txt";
	int num = -10;
	int numOct = 42;

	c = 'v';
	f = 'f';
	ft_conversions(" %c %c %s %d %i\n", c, f, nome,num,numOct);
	printf("\nOriginal: %c %c %s %d %i ", c, f, nome,num,numOct);
}
