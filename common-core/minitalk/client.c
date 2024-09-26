/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:39:54 by lfranco           #+#    #+#             */
/*   Updated: 2024/03/08 18:45:59 by lfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "./ft_printf/libftprintf.h"
#include "./libft/libft.h"
#include <signal.h>

void	convert(char *str, int pid)
{
	int	i;
	int	count;
	int	byte;

	i = 0;
	count = 0;
	while (str[i])
	{
		byte = str[i];
		while (count < 8)
		{
			if ((byte % 2) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(800);
			count++;
			byte /= 2;
		}
		usleep(800);
		i++;
		count = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = ft_atoi(av[1]);
	if (ac != 3)
		return (1);
	convert(av[2], pid);
	return (0);
}
