/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:00:15 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/23 10:58:59 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	g_sig_from_server;

void	send_by_bits(int pid, char *s)
{
	int	i;

	while (*s != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if (*s & (1 << i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (!g_sig_from_server)
				;
			g_sig_from_server = 0;
			i--;
		}
		s++;
	}
}

void	handler(int sig)
{
	g_sig_from_server = sig;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Client requires two parameters\n");
		return (1);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	g_sig_from_server = 0;
	send_by_bits(ft_atoi(argv[1]), argv[2]);
	return (0);
}
