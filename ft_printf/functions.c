#include "ft_printf.h"



int printbase(long nbr, int base)
{
    int count;
    char *symbols;

    symbols = "0123456789abcdef";


    if(nbr < 0)
    {
        write(1,"-",1);
        return  printbase(-nbr,base) + 1;//+1 por causa do -
    }
    else if(nbr < base)
    {
          return ft_putchar(symbols[nbr]);
    }else{
        count = printbase(nbr / base,base);
        return count + printbase(nbr % base,base);
    }
}
int printbaseupper(long nbr, int base)
{
    int count;
    char *symbols16;

    symbols16 = "0123456789ABCDEF";

    if(nbr < 0)
    {
        write(1,"-",1);
        return  printbaseupper(-nbr,base) + 1;//+1 por causa do -
    }
    else if(nbr < base)
    {
          return ft_putchar(symbols16[nbr]);
    }else{
        count = printbaseupper(nbr / base,base);
        return count + printbaseupper(nbr % base,base);
    }
}
