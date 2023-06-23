/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:00:19 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/23 10:53:00 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	g_char_buf;

void	handler(int sig, struct __siginfo *info, void *p)
{
	ssize_t	res;

	(void)p;
	g_char_buf = (g_char_buf << 1) | (sig - SIGUSR1);
	if (g_char_buf & (1 << 8))
	{
		res = write(1, &g_char_buf, 1);
		g_char_buf = 1;
		if (res == -1)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	g_char_buf = 1;
	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		;
}
