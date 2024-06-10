#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
int ft_putchar(char a);
int check_conversion(char a);
int call_function(int j, int counter, va_list args);
int ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);
int ft_num_len(int nb);
int ft_puthex_low(unsigned int nb);
int ft_puthex_up(unsigned int nb);

int ft_printf(const char *format, ...)
{
    va_list args;
    int counter;
    int i;
    int j;

    i = 0;
    counter = 0;
    va_start(args, format);
    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            counter += ft_putchar(format[i]);
            i++;
        }
        else 
        {
            j = check_conversion(format[i + 1]);
            counter = call_function(j, counter, args);
            i += 2;
        }
    }
    va_end(args);
    return (counter);
}

int call_function(int j, int counter, va_list args)
{   
    if (j == 0)
        counter += ft_putchar(va_arg(args, int));
    if (j == 1)
        counter += ft_putstr(va_arg(args, char *));
    // if (j == 2)
    // {

    // }
    if (j == 3)
        counter += ft_putnbr(va_arg(args, int));
    if (j == 4)
        counter += ft_putnbr(va_arg(args, int));
    if (j == 5)
        counter += ft_putnbr_u(va_arg(args, unsigned int));
    if (j == 6)
        counter += ft_puthex_low(va_arg(args, unsigned int));
    if (j == 7)
        counter += ft_puthex_up(va_arg(args, unsigned int));
    if (j == 8)
        counter += ft_putchar('%');
    return (counter);
}

int ft_putchar(char a)
{
    write(1, &a, 1);
    return (1);
}

int ft_putstr(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar(s[i]);
        i++;
    }
    return (i);
}

int	ft_putnbr(int nb)
{
	unsigned int	nbr;
    unsigned int	nbrcpy;
    int counter;

    counter = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
        counter ++;
	}
	else
		nbr = nb;
    nbrcpy = nbr;
    if (nbrcpy == 0)
       counter = 1;
    while (nbrcpy != 0)
    {
        counter ++;
        nbrcpy /= 10;
    }
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    ft_putchar(nbr % 10 + 48);
    return (counter);
}

int	ft_putnbr_u(unsigned int nb)
{
	unsigned int	nbr;
    unsigned int	nbrcpy;
    int counter;

    counter = 0;
	nbr = nb;
    nbrcpy = nbr;
    if (nbrcpy == 0)
       counter = 1;
    while (nbrcpy != 0)
    {
        counter ++;
        nbrcpy /= 10;
    }
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    ft_putchar(nbr % 10 + 48);
    return (counter);
}

int ft_num_len(int nb)
{
    int len;

    len = 0;
    if (nb == 0)
        len = 1;
    while (nb != 0)
    {
        len ++;
        nb/= 16;
    }
    return (len);
}
int ft_puthex_low(unsigned int nb)
{
    unsigned int nbr;
    char *str;
    int i;

    if (nb == 0)
        ft_putchar('0');
    nbr = nb;
    i = (ft_num_len(nb));
    str = malloc((i + 1) * sizeof(char));
    if (!str)
        return (0);
    str [i] = '\0';
    i--;
    while (nb != 0)
    {
        if ((nb % 16) < 10)
            str[i--] = nb % 16 + '0';
        else
            str[i--] = nb % 16 + 87;
        nb /= 16;
    }
    ft_putstr(str);
    return (ft_num_len(nbr));
}

int ft_puthex_up(unsigned int nb)
{
    unsigned int nbr;
    char *str;
    int i;

    if (nb == 0)
        ft_putchar('0');
    nbr = nb;
    i = (ft_num_len(nb));
    str = malloc((i + 1) * sizeof(char));
    if (!str)
        return (0);
    str [i] = '\0';
    i--;
    while (nb != 0)
    {
        if ((nb % 16) < 10)
            str[i--] = nb % 16 + '0';
        else
            str[i--] = nb % 16 + 55;
        nb /= 16;
    }
    ft_putstr(str);
    return (ft_num_len(nbr));
}
// int ft_putptr(void *ptr)
// {

// }

int check_conversion(char a)
{
    int i;
    char *conversions;

    i = 0;
    conversions = "cspdiuxX%";
    while (conversions[i] != '\0')
    {
        if (a == conversions[i])
            return (i);
        i++;
    }
    return (-1);
}

int main()
{
    int i;
    int j;

    printf("test1\n");
    i = printf("ABC\n");
    j = ft_printf("ABC\n");
    if (i == j)
        printf("OK\n\n");
    else 
        printf("ERROR\n\n");

    printf("test2\n");
    i = printf("ABC%%\n");
    j = ft_printf("ABC%%\n");
    if (i == j)
        printf("OK\n\n");
    else 
        printf("ERROR\n\n");

    printf("test3\n");
    i = printf("ABC%c\n", 'D');
    j = ft_printf("ABC%c\n", 'D');
    if (i == j)
        printf("OK\n\n");
    else 
        printf("ERROR\n\n");
        
    printf("test4\n");
    i = printf("ABC%s\n", "DEFG");
    j = ft_printf("ABC%s\n", "DEFG");
    if (i == j)
        printf("OK\n\n");
    else 
        printf("ERROR\n\n");

    printf("test5\n");
    i = printf("ABC%s%%%cIJK\n", "DEFG", 'H');
    j = ft_printf("ABC%s%%%cIJK\n", "DEFG", 'H');
    if (i == j)
        printf("OK\n\n");
    else 
        printf("ERROR\n\n");

    printf("test6\n");
    i = printf("ABC%d\n", 0);
    j = ft_printf("ABC%d\n", 0);
    if (i == j)
        printf("OK\n\n");
    else 
        printf("ERROR\n\n");
    
    printf("test7\n");
    i = printf("ABC%i\n", 1567);
    j = ft_printf("ABC%i\n", 1567);
    if (i == j)
        printf("OK\n\n");
    else 
        printf("ERROR\n\n");

    printf("test8\n");
    i = printf("ABC%u\n", -1567);
    j = ft_printf("ABC%u\n", -1567);
    if (i == j)
        printf("OK\n\n");
    else 
        printf("ERROR\n\n");

    printf("test9\n");
    i = printf("ABC%x\n", 0);
    j = ft_printf("ABC%x\n", 0);
    if (i == j)
        printf("OK\n\n");
    else 
        printf("ERROR\n\n");
    
    printf("test10\n");
    i = printf("ABC%X\n", 1576757);
    j = ft_printf("ABC%X\n", 1576757);
    if (i == j)
        printf("OK\n\n");
    else 
        printf("ERROR\n\n");
}