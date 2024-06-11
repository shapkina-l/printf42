#include "ft_printf.h"

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