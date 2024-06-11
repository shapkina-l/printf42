/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshapkin <lshapkin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:19:07 by lshapkin          #+#    #+#             */
/*   Updated: 2024/06/11 16:53:29 by lshapkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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