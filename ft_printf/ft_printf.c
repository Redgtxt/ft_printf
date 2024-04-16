#include "ft_printf.h"

int	ft_conversions(const char *format, va_list args)
{
	int count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if(*format == 'p')
		return 0;
	else if(*format == 'd' || *format == 'i')
		printbase(va_arg(args,int),10);
	else if(*format == 'u')
		return 1;
	else if(*format == 'x')
		count +=	printbase(va_arg(args,unsigned int),16);
	else if(*format == 'X')
		count +=	printbaseupper(va_arg(args,unsigned int),16);
	else if(*format == '%')
		count += putchar('%');

return 0;
}

 int ft_printf(const char *str, ...)
{
	int i;
	va_list args;
	int count;

	count = 0;
	i = 0;
	va_start(args,str);
	while (str[i])
	{
		if(str[i] == '%')
		{
			i++;
			count += ft_conversions(&str[i], args);
		}else{
			 count += write(1,&str[i],1);
		}
		i++;
	}
	va_end(args);
	return count;
 }

int	main(void)
{
	// char	c;
	// char	f;
	// char	nome[] = "Txt";
	// int num = -10;
	// int numOct = 42;

	// c = 'v';
	// f = 'f';

	// printf("\nOriginal: %c %c %s %d %i \n", c, f, nome,num,numOct);
	// ft_printf("\nMeu: %c %c %s %d %i \n", c, f, nome,num,numOct);

	ft_printf("\n%%\n");
	printf("\nTrue:%u\n",-19);



}
