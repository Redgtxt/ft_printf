#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;

	va_start(args,format);

	while (*format)
	{
		if(*format == '%')
		{
			format++;
			if(*format == 'c')
			{
				ft_putchar_fd(va_arg(args,int),1);
			}
		}
		format++;
	}
	va_end(args);
return 0;
}

int main(void)
{
	char c;
	c = 'v';
	char f;
	f = 'f';
	ft_printf("%c %f",c,f);
}
