/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshapkin <lshapkin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:51:01 by lshapkin          #+#    #+#             */
/*   Updated: 2024/06/11 17:05:25 by lshapkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_putchar(char a);
int check_conversion(char a);
int call_function(char conversion, int counter, va_list args);
int ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);
int ft_num_len(int nb);
int ft_puthex_low(unsigned int nb);
int ft_puthex_up(unsigned int nb);
int ft_printf(const char *format, ...);
int ft_num_len_ptr(unsigned long long nb);
int ft_putptr(unsigned long long nb);