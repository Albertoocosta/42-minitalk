/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:31:36 by cda-fons          #+#    #+#             */
/*   Updated: 2024/09/17 20:54:20 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handle(int signum)
{
	static int bit;
	static int i;
	
	if (signum == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	(void)argv;

	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	else
	{
		pid = getpid();
		if (pid == -1)
		{
			ft_printf("error pid\n");
		}
		ft_printf("%d\n", pid);
		while (1)
		{
			signal(SIGUSR1, sig_handle);
			signal(SIGUSR2, sig_handle);
			pause();
		}
	}
	return (0);
}