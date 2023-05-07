/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 07:35:12 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/07 21:26:56 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_char	g_ch;

void	sigusr1_handler(int signo, siginfo_t *info, void *p)
{
	(void)signo;
	(void)info;
	(void)p;
	g_ch.ch = (g_ch.ch << 1);
	g_ch.bit_cnt++;
	if (g_ch.bit_cnt == 8)
	{
		write(1, &g_ch.ch, 1);
		g_ch.ch = 0;
		g_ch.bit_cnt = 0;
	}
}

void	sigusr2_handler(int signo, siginfo_t *info, void *p)
{
	(void)signo;
	(void)info;
	(void)p;
	g_ch.ch = (g_ch.ch << 1);
	g_ch.ch += 1;
	g_ch.bit_cnt++;
	if (g_ch.bit_cnt == 8)
	{
		write(1, &g_ch.ch, 1);
		g_ch.ch = 0;
		g_ch.bit_cnt = 0;
	}
}

int	main(void)
{
	pid_t	pid;
	struct sigaction	act1;
	struct sigaction	act2;

	pid = getpid();
	ft_printf("%d\n", pid);
	g_ch.bit_cnt = 0;
	g_ch.ch = 0;
	act1.sa_sigaction = sigusr1_handler;
	sigemptyset(&act1.sa_mask);
	act1.sa_flags = SA_SIGINFO;
	act2.sa_sigaction = sigusr2_handler;
	sigemptyset(&act2.sa_mask);
	act2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act2, NULL);
	while (1)
		pause();
}
