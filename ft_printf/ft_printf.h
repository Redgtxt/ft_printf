
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c);
int ft_putstr(char *s);
int printbase(long nbr, int base,char *symbols);
int ft_putptr_base(unsigned long long ptr,char *base,int f);
int	ft_conversions(const char *format, va_list args);
int ft_printf(const char *str, ...);
