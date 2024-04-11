#include "ft_printf.h"

void ft_putnbr_fd(int n,int fd)
{

    if(n < 0)
    {
        if(n == -2147483648)
        {
            ft_putstr_fd("-2147483648", fd);
            return;
        }

        ft_putchar_fd('-',fd);
        n *= -1;
    }

    if(n > 9)
    {
        ft_putnbr_fd(n / 10,fd);
        ft_putnbr_fd(n % 10,fd);

    }else
        ft_putchar_fd(n + '0',fd);

}

