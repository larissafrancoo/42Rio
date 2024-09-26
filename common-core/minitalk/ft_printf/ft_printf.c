/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco <lfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:44:47 by lfranco           #+#    #+#             */
/*   Updated: 2023/11/30 17:00:22 by lfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int	ft_checker(char c, va_list li)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(li, int));
	else if (c == 's')
		len += ft_putstr(va_arg(li, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(li, int));
	else if (c == 'p')
		len += ft_putptr(va_arg(li, long unsigned int));
	else if (c == 'u')
		len += ft_putbase(va_arg(li, unsigned int), 10, 0);
	else if (c == 'X')
		len += ft_putbase(va_arg(li, unsigned int), 16, 1);
	else if (c == 'x')
		len += ft_putbase(va_arg(li, unsigned int), 16, 0);
	else if (c == '%')
		len += ft_putchar('%');
	else
		return (0);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	li;

	if (!str)
		return (-1);
	i = 0;
	len = 0;
	va_start (li, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			len += ft_checker(str[++i], li);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}
/*
#include <stdio.h>
int main(void)
{
	char c = 'x';
	char s[] = "sdpqheiodpeqipd";
//	int n = -5;
//	int nu = 0;
//	int num = 2023;
//	int hex = 47368432;

	int ori = ft_printf("Orig: \n %   c\n", c);
	int jack = printf("Jack: \n %   c\n", c);

	printf("\n Orig: %d \n", ori);
	printf("\n Jack: %d \n", jack);
	return (0);
}*/
