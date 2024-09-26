/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco <lfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:29:01 by lfranco           #+#    #+#             */
/*   Updated: 2024/06/26 16:38:51 by larissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s_one;
	unsigned char	*s_two;

	i = 0;
	s_one = (unsigned char *)s1;
	s_two = (unsigned char *)s2;
	while (!(!s_one[i] && !s_two[i]))
	{
		if ((s_one[i] == s_two[i])
			&& (s_one[i] != '\0' || s_two[i] != '\0'))
			i++;
		else
			return (s_one[i] - s_two[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*la = "test";
	char	*ri = "testabc";

	printf("Jack Sparrow: %d \n", ft_strcmp(la, ri));
	printf("Original    : %d \n", strcmp(la, ri));
	return (0);
}
*/
