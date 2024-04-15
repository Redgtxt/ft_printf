#include "ft_printf.h"

int	ft_conversions(const char *format, va_list args)
{
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
return 0;
}

 int ft_printf(const char *str, ...)
 {
	int i;
	va_list args;

	i = 0;
	va_start(args,str);
	while (str[i])
	{
		if(str[i] == '%')
		{
			i++;
			// Pass the conversion specifier to ft_conversions
			ft_conversions(&str[i], args);
		}else{
			write(1,&str[i],1);
		}
		i++;
	}
	va_end(args);
	return(0);
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
	
	printf("\nOriginal: %c %c %s %d %i \n", c, f, nome,num,numOct);
	ft_printf("\nMeu: %c %c %s %d %i \n", c, f, nome,num,numOct);
	printf("Bom dia darling 45353\n");
	ft_printf("Bom dia darling 45353\n");
}
