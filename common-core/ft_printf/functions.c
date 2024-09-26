/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco <lfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:55:53 by lfranco           #+#    #+#             */
/*   Updated: 2023/11/29 20:03:20 by lfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putchar('-');
		len += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[len] != '\0')
		write (1, &s[len++], 1);
	return (len);
}

int	ft_putbase(long unsigned int n, unsigned int base, int up)
{
	int		len;
	char	*hexachars;

	if (up)
		hexachars = "0123456789ABCDEF";
	else
		hexachars = "0123456789abcdef";
	len = 0;
	if (n >= base)
	{
		len += ft_putbase(n / base, base, up);
		len += ft_putbase(n % base, base, up);
	}
	else
		len += ft_putchar(hexachars[n]);
	return (len);
}

int	ft_putptr(long unsigned int p)
{
	int	len;

	if (!p)
		return (ft_putstr("(nil)"));
	len = 0;
	len += ft_putstr("0x");
	len += ft_putbase(p, 16, 0);
	return (len);
}
/*
#include <stdio.h>
int main(void)
{
	int ret = ft_putnbr(-2147483648);
	printf("\nRet nbr : %d \n\n", ret);

	int stret = ft_putstr("123456789");
	printf("\nRet nbr : %d \n\n", ret);

	int hexaret = ft_putbase(898064, 16, 0);
	printf("\nRet nbr : %d \n\n", ret);

	char *ptret = ft_putptr("123456789");
	printf("\nRet nbr : %d \n\n", ret);
	return (0);
}*/
