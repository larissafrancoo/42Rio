/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:38:29 by lfranco           #+#    #+#             */
/*   Updated: 2024/05/01 06:28:43 by lfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_chars(char **av)
{
	int	i;
	int	o;

	i = 0;
	o = 1;
	while (av[o])
	{
		while (av[o][i])
		{
			if ((av[o][i] == '-' || av[o][i] == '+') && i == 0)
				i++;
			if (!(av[o][i] >= '0' && av[o][i] <= '9'))
				return (0);
			i++;
		}
		i = 0;
		o++;
	}
	return (1);
}

static int	check_int_limit(char **av)
{
	long int	number;
	int			o;

	o = 1;
	while (av[o])
	{
		number = ft_atol(av[o]);
		if (!(number >= -2147483648 && number <= 2147483647))
			return (0);
		o++;
	}
	return (1);
}

static int	check_dup_and_sort(char **av)
{
	int	o;
	int	i;
	int	flag;

	o = 1;
	i = 1;
	flag = 0;
	while (av[o])
	{
		while (i < o)
		{
			if (ft_atol(av[i]) > ft_atol(av[o]))
				flag = 1;
			else if (ft_atol(av[i]) == ft_atol(av[o]))
				return (1);
			i++;
		}
		i = 1;
		o++;
	}
	if (flag == 1)
		return (0);
	return (2);
}

void	checker_input(int ac, char **av)
{
	if (ac <= 2)
		return ;
	else
	{
		if (!(check_chars(av)))
			put_error("Error");
		else if (!(check_int_limit(av)))
			put_error("Error");
		else if (check_dup_and_sort(av) == 1)
			put_error("Error");
		else if (check_dup_and_sort(av) == 2)
			exit(0);
	}
}
