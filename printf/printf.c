#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int counter;
    int i;

    va_start(args, format);
    while (format[i] != '\0')
    {
        if (format[i] != '%')
            counter += ft_putchar(format[i]);
    }
//   while ...
//        va_arg(args, ??);
    va_end(args);
    return (counter);
}

int ft_putchar(char a)
{
    write(1, &a, 1);
    return (1);
}

int main()
{
    printf("test1\n");
    printf("ABC\n");
    ft_printf("ABC\n");
    if (printf("ABC\n") == ft_printf("ABC\n"))
        printf("OK\n");
    else 
        printf("ERROR\n");
}