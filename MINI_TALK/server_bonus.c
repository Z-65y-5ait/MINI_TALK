/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaimi <azaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 02:01:54 by azaimi            #+#    #+#             */
/*   Updated: 2024/12/28 22:30:27 by azaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	received_signal(int sig, siginfo_t *info, void *content)
{
	static int	bits;
	static char	byte;
	static int	prev_pid;

	(void)content;
	if (prev_pid != info->si_pid)
	{
		prev_pid = info->si_pid;
		bits = 0;
		byte = 0;
	}
	byte = byte << 1;
	if (sig == SIGUSR2)
		byte |= 1;
	bits++;
	if (bits == 8)
	{
		if (byte == '\0')
			write(1, "\n", 1);
		else
			write(1, &byte, 1);
		bits = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	man;

	(void)argv;
	if (argc != 1)
	{
		write(1, "error", 5);
		return (-1);
	}
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigemptyset(&man.sa_mask);
	man.sa_flags = SA_SIGINFO;
	man.sa_sigaction = received_signal;
	if (sigaction(SIGUSR1, &man, NULL) == -1
		|| sigaction(SIGUSR2, &man, NULL) == -1)
		return (-1);
	while (1)
		pause();
	return (0);
}
