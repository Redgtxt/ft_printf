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
		count += ft_putptr_base(va_arg(args,unsigned long),"0123456789abcdef",0);
	else if(*format == 'd' || *format == 'i')
		count += printbase(va_arg(args,int),10,"0123456789");
	else if(*format == 'u')
		count += printbase(va_arg(args,unsigned int),10,"0123456789");
	else if(*format == 'x')
		count +=	printbase(va_arg(args,unsigned int),16,"0123456789abcdef");
	else if(*format == 'X')
		count +=	printbase(va_arg(args,unsigned int),16,"0123456789ABCDEF");
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
	 int numOct = 42;
	 int *endereco = &numOct;
	 int size;

	// c = 'v';
	// f = 'f';

	// printf("\nOriginal: %c %c %s %d %i \n", c, f, nome,num,numOct);
	// ft_printf("\nMeu: %c %c %s %d %i \n", c, f, nome,num,numOct);

	size = ft_printf("%p",endereco);
	printf("\nTrue:%p \n",endereco);
	ft_printf("\nO size do meu printf e: %d \n",size);


}
