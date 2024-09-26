/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:40:02 by lfranco           #+#    #+#             */
/*   Updated: 2024/03/08 18:43:05 by lfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "./ft_printf/libftprintf.h"
#include <signal.h>

void	server(int sign)
{
	static int	i;
	static int	bin[8] = {1, 2, 4, 8, 16, 32, 64, 128};
	static int	byte;

	if (sign == SIGUSR1)
		byte += bin[i];
	if (i == 7)
	{
		write(1, &byte, 1);
		i = 0;
		byte = 0;
	}
	else
		i++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d \n", pid);
	while (1)
	{
		signal (SIGUSR1, server);
		signal (SIGUSR2, server);
		pause ();
	}
}
