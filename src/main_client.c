/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:35:20 by ahooghe           #+#    #+#             */
/*   Updated: 2023/04/03 13:38:27 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk.h"

void	signal_error(void)
{
	ft_printf("\nClient: unexpected error.\n");
	exit(EXIT_FAILURE);
}

void	char_to_bin(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				signal_error();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				signal_error();
		}
		c <<= 1;
		bit++;
		pause();
		usleep(100);
	}
}

void	sent_text(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		char_to_bin(str[i++], pid);
	char_to_bin('\0', pid);
}

void	recieved(int sig)
{
	static int	sent;

	if (sig == SIGUSR1)
	{
		ft_printf("%d signal sent successfully!\n", ++sent);
		exit(EXIT_SUCCESS);
	}
	if (sig == SIGUSR2)
		++sent;
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	client_pid;

	client_pid = getpid();
	if (ac == 3)
	{
		ft_printf("client pid: %d\n", client_pid);
		signal(SIGUSR1, recieved);
		signal(SIGUSR2, recieved);
		server_pid = ft_atoi(av[1]);
		ft_printf("Text currently sending.. \n");
		sent_text(av[2], server_pid);
	}
	else
		ft_printf("Usage: ./client <server_pid> <text to send>\n");
	return (EXIT_FAILURE);
}