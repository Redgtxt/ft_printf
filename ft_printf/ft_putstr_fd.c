#include "ft_printf.h"

void ft_putstr_fd(char *s,int fd)
{
    int i;

    if(!s)
        return;

    i = 0;
    while(s[i] !='\0')
    {
        write(fd,&s[i],1);
        i++;
    }

}

/*
int main(void)
{
	char nome[] = "wd-40";
	printf("%s",nome);
}
*/