/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:31:33 by cda-fons          #+#    #+#             */
/*   Updated: 2024/09/17 20:30:14 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	tobinary(int pid, char 	letter)
{
	int	bit;
	
	bit = 0;
	while (bit < 8)
	{
		if ((letter & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

void	message_handle(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		tobinary(pid, message[i]);
		i++;
	}
	tobinary(pid, '\n');
}

int	main(int argc, char **argv)
{	
	if (argc != 3)
		return(1);
	message_handle(ft_atoi(argv[1]), argv[2]);
	return (0);
}
