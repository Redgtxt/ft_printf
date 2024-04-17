#include "ft_printf.h"



int printbase(long nbr, int base,char *symbols)
{
    int count;
    if(nbr < 0)
    {
        write(1,"-",1);
        return  printbase(-nbr,base,symbols) + 1;//+1 por causa do -
    }
    else if(nbr < base)
    {
          return ft_putchar(symbols[nbr]);
    }else{
        count = printbase(nbr / base,base,symbols);
        return count + printbase(nbr % base,base,symbols);
    }
}
