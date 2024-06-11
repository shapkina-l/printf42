/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshapkin <lshapkin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:19:11 by lshapkin          #+#    #+#             */
/*   Updated: 2024/06/11 17:05:19 by lshapkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_num_len_ptr(unsigned long long nb)
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

int ft_putptr(unsigned long long nb)
{
    unsigned int nbr;
    char *str;
    int i;

    if (nb == 0)
        ft_putchar('0');
    nbr = nb;
    i = (ft_num_len_ptr(nb));
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
    return (ft_num_len_ptr(nbr));
}